#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <windows.h>
#include <algorithm> // funkcja sort()
#include <sstream>
#include <string.h>
#include <iomanip>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomesManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    double incomesAmount;

    Income inputDataOfTheNewIncome();
    bool static less_than_key(const Income& struct1, const Income& struct2);

public:
    IncomesManager (string nameOfFileWithIncomes, int loggedInUserId)
    : fileWithIncomes(nameOfFileWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
    incomes = fileWithIncomes.loadIncomesBelongToLoggedInUserFromTheFile(LOGGED_IN_USER_ID);
    incomesAmount = 0;
    }

    void addIncome();
    double balanceOfTheIncomesInTheCurrentMonth();
    double balanceOfTheIncomesInThePreviousMonth();
    double balanceOfTheIncomesInTheSelectedTime(string startingDate, string endDate);
    double getIncomesAmount();
};

#endif
