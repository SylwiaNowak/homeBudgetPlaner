#include "HomeFinanceCalculator.h"

/*HomeFinanceCalculator::HomeFinanceCalculator() {
    //userManager.loadUsersFromTheFile();
    //userManager.showUsers();
}*/

bool HomeFinanceCalculator::isTheUserLoggedIn() {
    userManager.isTheUserLoggedIn();
}

char HomeFinanceCalculator::chooseOptionFromTheMainMenu() {
    userManager.chooseOptionFromTheMainMenu();
}

char HomeFinanceCalculator::chooseOptionFromTheUserMenu() {
    userManager.chooseOptionFromTheUserMenu();
}

void HomeFinanceCalculator::userRegistration() {
    userManager.userRegistration();
}

void HomeFinanceCalculator::logInTheUser() {
    userManager.logInTheUser();
    if (userManager.isTheUserLoggedIn()) {
        incomesManager = new IncomesManager(NAME_OF_FILE_WITH_INCOMES, userManager.getIdOfTheLoggedInUser());
    }
    /*if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }*/
}

void HomeFinanceCalculator::changeThePasswordOfTheLoggedInUser() {
    userManager.changeThePasswordOfTheLoggedInUser();
}

void HomeFinanceCalculator::logOutTheUser() {
    userManager.logOutTheUser();
    delete incomesManager;
    incomesManager = NULL;
}

void HomeFinanceCalculator::addIncome() {
    if (userManager.isTheUserLoggedIn()) {
        incomesManager -> addIncome();
    } else {
        cout << "If you want to add income, you have to be logged in first." << endl;
        system("pause");
    }
}

void HomeFinanceCalculator::addExpense() {
    if (userManager.isTheUserLoggedIn()) {
        expensesManager -> addExpense();
    } else {
        cout << "If you want to add expense, you have to be logged in first." << endl;
        system("pause");
    }
}

void HomeFinanceCalculator::balanceOfTheCurrentMonth() {
    if (userManager.isTheUserLoggedIn()) {
        incomesManager -> balanceOfTheIncomesInTheCurrentMonth();
    } else {
        cout << "If you want to generate balance of the current month, you have to be logged in first." << endl;
        system("pause");
    }
}

void HomeFinanceCalculator::balanceOfThePreviousMonth() {
    if (userManager.isTheUserLoggedIn()) {
        incomesManager -> balanceOfTheIncomesInThePreviousMonth();
    } else {
        cout << "If you want to generate balance of the previous month, you have to be logged in first." << endl;
        system("pause");
    }
}

void HomeFinanceCalculator::balanceOfTheSelectedTime() {
    if (userManager.isTheUserLoggedIn()) {
        incomesManager -> balanceOfTheIncomesInTheSelectedTime();
    } else {
        cout << "If you want to generate balance of the selected time, you have to be logged in first." << endl;
        system("pause");
    }
}
