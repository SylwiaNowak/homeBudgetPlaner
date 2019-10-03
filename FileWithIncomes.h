#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <cstdlib>
#include <sstream>
#include <stdlib.h> //atof();

#include "Income.h"
#include "AuxiliaryMethods.h"
//#include "PlikTekstowy.h"

using namespace std;

class FileWithIncomes//:public PlikTekstowy
{
    const string NAME_OF_FILE_WITH_INCOMES;

    int lastIncomeId;

public:
    FileWithIncomes(string nameOfFileWithIncomes) : NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes) {

        lastIncomeId = 0;
    };
    bool saveTheIncomeToTheFile(Income income);
    vector <Income> loadIncomesBelongToLoggedInUserFromTheFile(int loggedInUserId);
    int getLastIncomeId();
};

#endif
