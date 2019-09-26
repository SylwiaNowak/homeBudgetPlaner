#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <windows.h>
#include <sstream>


#include "User.h"
//#include "Income.h"
//#include "Expense.h"
#include "AuxiliaryMethods.h" //nie ma tego we wzorze
#include "FileWithUsers.h"
//#include "IncomesManager.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;

    User inputDataOfTheNewUser(); //Uzytkownik podajDaneNowegoUzytkownika(); // FUCKCJA POMOCNICZA PRZY REJESTRACJI
    int getIdOfTheNewUser(); //pobierzIdNowegoUzytkownika()
    bool isTheLoginExist(string login); //bool czyIstniejeLogin(string login);
    FileWithUsers fileWithUsers;

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromTheFile();
    };
    char chooseOptionFromTheMainMenu();
    char chooseOptionFromTheUserMenu();
    void userRegistration();
    void showUsers(); //void wypiszWszystkichUzytkownikow();
    void logInTheUser();
    void changeThePasswordOfTheLoggedInUser();
    void logOutTheUser();
//vector <User> loadUsersFromTheFile();
    bool isTheUserLoggedIn();
    int getIdOfTheLoggedInUser();
};

#endif
