#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <windows.h>
#include <algorithm> // funkcja sort()
#include <sstream>
#include <string.h>
#include <iomanip>



#include "Expense.h"
#include "AuxiliaryMethods.h"

#include "FileWithExpenses.h"

using namespace std;

class ExpensesManager {
    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;
    //AuxiliaryMethods auxiliaryMethods;

    //char chooseOptionFromDateMenu(); //POWTARZA SIE
    //char chooseOptionFromRepairDateMenu(); //POWTARZA SIE
    Expense inputDataOfTheNewExpense();







    //double returnAmountInCorrectFormat(string amountToCheck);//POWTARZA SIE
    //bool checkIfTheDateIsCorrect(string date);//POWTARZA SIE

    bool static less_than_key(const Expense& struct1, const Expense& struct2);

public:
    ExpensesManager (string nameOfFileWithExpenses, int loggedInUserId)
    : fileWithExpenses(nameOfFileWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
    expenses = fileWithExpenses.loadExpensesBelongToLoggedInUserFromTheFile(LOGGED_IN_USER_ID);


    }

    void addExpense();
    double balanceOfTheExpensesInTheCurrentMonth();
    double balanceOfTheExpensesInThePreviousMonth();
    double balanceOfTheExpensesInTheSelectedTime();






};

#endif
