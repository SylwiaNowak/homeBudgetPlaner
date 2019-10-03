#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <cstdlib> // funkcja atoi

#include "User.h"
#include "AuxiliaryMethods.h"
//#include "PlikTekstowy.h"

using namespace std;

class FileWithUsers//:public PlikTekstowy
{
    const string NAME_OF_FILE_WITH_USERS;
    vector <User> users;

public:
    FileWithUsers(string fileWithUsers) : NAME_OF_FILE_WITH_USERS(fileWithUsers) {

    };
    void saveNewUserToTheFile(User user);
    vector <User> loadUsersFromTheFile();
    void saveAllUsersToTheFile(vector <User> &users);
};

#endif
