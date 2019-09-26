#include <iostream>
#include "windows.h"

#include "HomeFinanceCalculator.h"
//#include "FileWithExpenses.h"
//#include "IncomesManager.h"
//#include "UserManager.h"


using namespace std;

int main() {
    char choice;
    //HomeFinanceCalculator homeFinanceCalculator;
    HomeFinanceCalculator homeFinanceCalculator("users.xml", "incomes.xml", "expenses.xml");
    //UserManager userManager("users.xml");

    while (true) {
        if (homeFinanceCalculator.isTheUserLoggedIn() == false) {
            choice = homeFinanceCalculator.chooseOptionFromTheMainMenu();

            switch (choice) {
            case '1':
                homeFinanceCalculator.userRegistration();
                break;
            case '2':
                homeFinanceCalculator.logInTheUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is not the option like this. Please, try again." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = homeFinanceCalculator.chooseOptionFromTheUserMenu();

            switch (choice) {
            case '1':
                homeFinanceCalculator.addIncome();
                break;
            case '2':
                homeFinanceCalculator.addExpense();
                break;
            case '3':
                homeFinanceCalculator.balanceOfTheCurrentMonth();
                break;
            case '4':
                homeFinanceCalculator.balanceOfThePreviousMonth();
                break;
            case '5':
                homeFinanceCalculator.balanceOfTheSelectedTime();
                break;
            case '6':
                homeFinanceCalculator.changeThePasswordOfTheLoggedInUser();
                break;
            case '8':
                homeFinanceCalculator.logOutTheUser();
                break;
            }
        }
    }
    return 0;
}


/*int main() {
    UserManager userManager ("users.xml");
    FileWithIncomes fileWithIncomes ("incomes.xml");
    IncomesManager incomesManager ("incomes.xml", 0);

    int lastIncomeId;
    int LOGGED_IN_USER_ID;

    lastIncomeId = fileWithIncomes.getLastIncomeId();
    userManager.logInTheUser();
    LOGGED_IN_USER_ID = userManager.downloadIdOfTheLoggedInUser();

    cout << endl << "Id rzeczy: " << lastIncomeId << endl;
    cout << "Id zalogowanego uzytkownika: " << LOGGED_IN_USER_ID;

    system("pause");

    return 0;
}*/
