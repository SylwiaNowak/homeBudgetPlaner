#ifndef HOMEFINANCECALCULATOR_H
#define HOMEFINANCECALCULATOR_H

#include <iostream>

//#include "Markup.h"
#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"

using namespace std;

class HomeFinanceCalculator {
    UserManager userManager;
    IncomesManager *incomesManager;
    ExpensesManager *expensesManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    HomeFinanceCalculator(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
    : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        incomesManager = NULL;
        expensesManager = NULL;
    };
    ~HomeFinanceCalculator()
    {
        delete incomesManager;
        delete expensesManager;
        incomesManager = NULL;
        expensesManager = NULL;
    };

    char chooseOptionFromTheMainMenu();
    char chooseOptionFromTheUserMenu();
    bool isTheUserLoggedIn();
    void userRegistration();
//void wypiszWszystkichUzytkownikow();
    void logInTheUser();
    void changeThePasswordOfTheLoggedInUser();
    void logOutTheUser();
    void addIncome();
    void addExpense();
    void balanceOfTheCurrentMonth();
    void balanceOfThePreviousMonth();
    void balanceOfTheSelectedTime();
//void wyszukajAdresatowPoImieniu();
//void wyszukajAdresatowPoNazwisku();
//void wyswietlWszystkichAdresatow();
//void usunAdresata();
//void edytujAdresata();
};

#endif
