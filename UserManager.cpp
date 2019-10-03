#include "UserManager.h"

char UserManager::chooseOptionFromTheMainMenu(){
    AuxiliaryMethods auxiliaryMethods;
    char choice;

    system("cls");
    cout << "    >>> THE MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log in" << endl;
    cout << "9. The end of the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadTheSign();

    return choice;
}

char UserManager::chooseOptionFromTheUserMenu() {
    AuxiliaryMethods auxiliaryMethods;
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance sheet of the current month" << endl;
    cout << "4. Balance sheet of the previous month" << endl;
    cout << "5. Balance sheet of the selected month" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change the password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadTheSign();

    return choice;
}

void UserManager::userRegistration() {
    User user = inputDataOfTheNewUser();
    users.push_back(user);
    fileWithUsers.saveNewUserToTheFile(user);

    cout << endl << "Account is done successfully." << endl << endl;
    getchar();getchar();
}

User UserManager::inputDataOfTheNewUser() {
    User user;

    int userId;
    string name, surname, login, password;

    userId = getIdOfTheNewUser();
    user.setUserId(userId);
    cout << "Give your name: " << endl;
    cin >> name;
    user.setName(name);
    cout << "Give your surname: " << endl;
    cin >> surname;
    user.setSurname(surname);

    do {
        cout << "Give your login: " << endl;
        cin >> login;
        user.setLogin(login);
    } while (isTheLoginExist(user.getLogin()) == true);

    cout << "Give your password: " << endl;
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getIdOfTheNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isTheLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "ERROR. This login exist." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showUsers() {
    for (int i = 0; i< users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::logInTheUser() {
    string login = "", password = "";

    cout << endl << "Give your login: ";
    login = AuxiliaryMethods::loadTheLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login) {
            for (int attempt = 3; attempt > 0; attempt--) {
                cout << "Give your password. The number of attempts that have remained: " << attempt << ": ";
                password = AuxiliaryMethods::loadTheLine();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "You are logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "You give wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is not user with login like this." << endl << endl;
    system("pause");
    return;
}

void UserManager::changeThePasswordOfTheLoggedInUser() {
    string newPassword = "";
    cout << "Give new password: ";
    cin >> newPassword;

    if (isTheUserLoggedIn()) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            if (itr -> getUserId() == loggedInUserId) {
                itr -> setPassword(newPassword);
                cout << "Password is changed." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveAllUsersToTheFile(users);
    } else {
        cout << "If you want to change the password, you must be logged in first." << endl;
        system("pause");
    }
}

void UserManager::logOutTheUser() {
    loggedInUserId = 0;
}

bool UserManager::isTheUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getIdOfTheLoggedInUser() {
    return loggedInUserId;
}
