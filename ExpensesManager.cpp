#include "ExpensesManager.h"

void ExpensesManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = inputDataOfTheNewExpense();

    expenses.push_back(expense);
    if (fileWithExpenses.saveTheExpenseToTheFile(expense))
        cout << "New expense is added" << endl;
    else cout << "ERROR. It was not possible to add a new expense to the file." << endl;
    system("pause");

    /*system("cls");
    for (int i = 0; i < expenses.size(); i++) {
        cout << expenses[i].getExpenseId() << endl;
        cout << expenses[i].getUserId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl;
    }
    system("pause");*/
}

Expense ExpensesManager::inputDataOfTheNewExpense() {
    AuxiliaryMethods auxiliaryMethods;
    Expense expense;

    int ExpenseId, userId, dateConvertedToInt;
    string date, item, amount;
    double correctAmount;

    char choice;

    expense.setExpenseId(fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);

    choice = auxiliaryMethods.chooseOptionFromDateMenu();

    switch (choice) {
    case '1': {
        date = auxiliaryMethods.loadActuallyDate();
        cout << date << endl;
        break;
    }
    case '2': {
        cout << "Please enter date: ";
        date = AuxiliaryMethods::loadTheLine();

        if (auxiliaryMethods.checkIfTheDateIsCorrect(date) == false) {
            cout << "Error. The date format is incorrect." << endl;
            system("pause");

            choice = auxiliaryMethods.chooseOptionFromRepairDateMenu();
            switch (choice) {
            case '1':
                cout << "Please enter date: ";
                date = AuxiliaryMethods::loadTheLine();
                if (auxiliaryMethods.checkIfTheDateIsCorrect(date) == false) {
                    cout << "Error. The date format is incorrect. You are log out." << endl;
                    exit(0);
                }
                break;
            case '2':
                cout << "EXIT." << endl;
                exit(0);
                break;
            default:
                cout << "There is not the option like this. You are log out." << endl;
                exit(0);
                break;
            }
        }
    }
    }

    cout << "Give your item: " << endl;
    item = AuxiliaryMethods::loadTheLine();

    cout << "Give amount: " << endl;
    amount = AuxiliaryMethods::loadTheLine();;
    correctAmount = auxiliaryMethods.returnAmountInCorrectFormat(amount);

    dateConvertedToInt = auxiliaryMethods.convertStringToInt(auxiliaryMethods.convertStringDateToStringDateWithoutSeparatingCharakter(date));

    expense.setDate(dateConvertedToInt);
    expense.setItem(item);
    expense.setAmount(correctAmount);

    return expense;
}

bool ExpensesManager::less_than_key(const Expense& struct1, const Expense& struct2) {
    return (struct1.getDate() < struct2.getDate());
}

double ExpensesManager::balanceOfTheExpensesInTheCurrentMonth() {
    Expense expense;
    AuxiliaryMethods auxiliaryMethods;
    int temporaryDateInInt = 0;
    string temporaryDateInString = "";
    expensesAmount = 0;
    int numberOfSelectedIncome = 1;

    vector <Expense>::iterator itr = expenses.begin();

    sort(expenses.begin(), expenses.end(), less_than_key);

    cout << endl << endl;
    cout << "----------- BALANCE OF THE CURRENT MONTH (EXPENSES) -----------" << endl;
    while (itr != expenses.end()) {
        temporaryDateInInt = itr -> getDate();

        if (auxiliaryMethods.checkingIfDateIsContainedInActuallyMonth(temporaryDateInInt) == true) {

            temporaryDateInString = auxiliaryMethods.convertIntToStringWithSeparatingCharacter(temporaryDateInInt);
            cout << numberOfSelectedIncome << " - " << temporaryDateInString << " - " << itr -> getItem() << " - " << itr -> getAmount() << endl;
            expensesAmount += itr -> getAmount();
            numberOfSelectedIncome++;
        }
        itr++;
        temporaryDateInInt = 0;
        temporaryDateInString = "";
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Amount of the expenses (of the current month): " << expensesAmount << endl;

    return 0;
}

double ExpensesManager::balanceOfTheExpensesInThePreviousMonth() {
    Expense expense;
    AuxiliaryMethods auxiliaryMethods;
    int temporaryDateInInt = 0;
    string temporaryDateInString = "";
    expensesAmount = 0;
    int numberOfSelectedIncome = 1;

    vector <Expense>::iterator itr = expenses.begin();

    sort(expenses.begin(), expenses.end(), less_than_key);

    cout << endl << endl;
    cout << "----------- BALANCE OF THE PREVIOUS MONTH (EXPENSES) -----------" << endl;
    while (itr != expenses.end()) {
        temporaryDateInInt = itr -> getDate();

        if (auxiliaryMethods.checkingIfDateIsContainedInPreviousMonth(temporaryDateInInt) == true) {
            temporaryDateInString = auxiliaryMethods.convertIntToStringWithSeparatingCharacter(temporaryDateInInt);
            cout << numberOfSelectedIncome << " - " << temporaryDateInString << " - " << itr -> getItem() << " - " << itr -> getAmount() << endl;
            expensesAmount += itr -> getAmount();
            numberOfSelectedIncome++;
        }
        itr++;
        temporaryDateInInt = 0;
        temporaryDateInString = "";
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Amount of the expenses (of the previous month): " << expensesAmount << endl;

    return 0;
}

double ExpensesManager::balanceOfTheExpensesInTheSelectedTime(string startingDate, string endDate) {
    Expense expense;
    AuxiliaryMethods auxiliaryMethods;
    int temporaryDateInInt = 0;
    string temporaryDateInString = "";
    expensesAmount = 0;

    int numberOfSelectedIncome = 1;

    vector <Expense>::iterator itr = expenses.begin();

    sort(expenses.begin(), expenses.end(), less_than_key);

    cout << endl << endl;

            cout << "----------- BALANCE OF THE SELECTED TIME (EXPENSES) -----------" << endl;
            while (itr != expenses.end()) {
                temporaryDateInInt = itr -> getDate();

                if (auxiliaryMethods.checkingIfDateIsContainedInSelectedTime(temporaryDateInInt, startingDate, endDate) == true) {
                    temporaryDateInString = auxiliaryMethods.convertIntToStringWithSeparatingCharacter(temporaryDateInInt);
                    cout << numberOfSelectedIncome << " - " << temporaryDateInString << " - " << itr -> getItem() << " - " << itr -> getAmount() << endl;
                    expensesAmount += itr -> getAmount();
                    numberOfSelectedIncome++;
                }
                itr++;
                temporaryDateInInt = 0;
                temporaryDateInString = "";
            }
            cout << fixed;
            cout << setprecision(2);
            cout << "Amount of the expenses (of the previous month): " << expensesAmount << endl;

    return 0;
}

double ExpensesManager::getExpensesAmount() {
    return expensesAmount;
}
