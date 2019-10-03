#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <windows.h>
#include <sstream>
#include <stdio.h> //getchar()

#include "User.h"
#include "AuxiliaryMethods.h" //nie ma tego we wzorze
#include "FileWithUsers.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;

    User inputDataOfTheNewUser();
    int getIdOfTheNewUser();
    bool isTheLoginExist(string login);
    FileWithUsers fileWithUsers;

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromTheFile();
    };
    char chooseOptionFromTheMainMenu();
    char chooseOptionFromTheUserMenu();
    void userRegistration();
    void showUsers();
    void logInTheUser();
    void changeThePasswordOfTheLoggedInUser();
    void logOutTheUser();
    bool isTheUserLoggedIn();
    int getIdOfTheLoggedInUser();
};

#endif
