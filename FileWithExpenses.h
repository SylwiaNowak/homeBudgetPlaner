#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <cstdlib>
#include <sstream>
#include <stdlib.h> //atof();

#include "Expense.h"
#include "AuxiliaryMethods.h"
//#include "PlikTekstowy.h"

using namespace std;

class FileWithExpenses//:public PlikTekstowy
{
    const string NAME_OF_FILE_WITH_EXPENSES;

    int lastExpenseId;










public:
    FileWithExpenses(string nameOfFileWithExpenses) : NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses) {

        lastExpenseId = 0;
    };
    bool saveTheExpenseToTheFile(Expense expense);
    vector <Expense> loadExpensesBelongToLoggedInUserFromTheFile(int loggedInUserId);
    int getLastExpenseId();



};

#endif
