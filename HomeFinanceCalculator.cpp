#include "HomeFinanceCalculator.h"

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
        expensesManager = new ExpensesManager(NAME_OF_FILE_WITH_EXPENSES, userManager.getIdOfTheLoggedInUser());
    }
}

void HomeFinanceCalculator::changeThePasswordOfTheLoggedInUser() {
    userManager.changeThePasswordOfTheLoggedInUser();
}

void HomeFinanceCalculator::logOutTheUser() {
    userManager.logOutTheUser();
    delete incomesManager;
    incomesManager = NULL;
    delete expensesManager;
    expensesManager = NULL;
}

void HomeFinanceCalculator::addIncome() {
    incomesManager -> addIncome();
}

void HomeFinanceCalculator::addExpense() {
    expensesManager -> addExpense();
}

void HomeFinanceCalculator::balanceOfTheCurrentMonth() {
    double amountOfBalance = 0;

    incomesManager -> balanceOfTheIncomesInTheCurrentMonth();
    expensesManager -> balanceOfTheExpensesInTheCurrentMonth();

    amountOfBalance = (incomesManager -> getIncomesAmount()) - (expensesManager -> getExpensesAmount());

    cout << endl << endl << "Balance of the current month is: " << amountOfBalance << endl;
    getchar();getchar();
}

void HomeFinanceCalculator::balanceOfThePreviousMonth() {
    double amountOfBalance = 0;
    incomesManager -> balanceOfTheIncomesInThePreviousMonth();
    expensesManager -> balanceOfTheExpensesInThePreviousMonth();

    amountOfBalance = (incomesManager -> getIncomesAmount()) - (expensesManager -> getExpensesAmount());

    cout << endl << endl << "Balance of the previous month is: " << amountOfBalance << endl;
    getchar();getchar();
}

void HomeFinanceCalculator::balanceOfTheSelectedTime() {
    AuxiliaryMethods auxiliaryMethods;
    string startingDate = "", endDate = "";
    double amountOfBalance = 0;

    system("cls");
    cout << "Enter date from which one you need to generate balance (in format yyyy-mm-dd): ";
    cin >> startingDate;
    if (auxiliaryMethods.checkIfTheDateIsCorrect(startingDate) == true) {
        cout << "Enter end date for which one you need to generate balance (in format yyyy-mm-dd): ";
        cin >> endDate;
        if (auxiliaryMethods.checkIfTheDateIsCorrect(endDate) == true) {
            incomesManager -> balanceOfTheIncomesInTheSelectedTime(startingDate, endDate);
            expensesManager -> balanceOfTheExpensesInTheSelectedTime(startingDate, endDate);
        } else {
            cout << "The end date format is incorrect. You come back to \"user menu\"." << endl;
            getchar();getchar();
            userManager.chooseOptionFromTheUserMenu();
        }
    } else {
        cout << "The end date format is incorrect. You come back to \"user menu\"." << endl;
        getchar();getchar();
        userManager.chooseOptionFromTheUserMenu();
    }

    amountOfBalance = (incomesManager -> getIncomesAmount()) - (expensesManager -> getExpensesAmount());

    cout << endl << endl << "Balance from: " << startingDate << " to: " << endDate << " is: " << amountOfBalance << endl;
    getchar();getchar();
}
