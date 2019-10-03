#include "IncomesManager.h"

void IncomesManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = inputDataOfTheNewIncome();

    incomes.push_back(income);
    if (fileWithIncomes.saveTheIncomeToTheFile(income))
        cout << "New income is added" << endl;
    else cout << "ERROR. It was not possible to add a new income to the file." << endl;
    system("pause");

    /*system("cls");
    for (int i = 0; i < incomes.size(); i++) {
        cout << incomes[i].getIncomeId() << endl;
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
    }
    system("pause");*/
}

Income IncomesManager::inputDataOfTheNewIncome() {
    AuxiliaryMethods auxiliaryMethods;
    Income income;

    int incomeId, userId, dateConvertedToInt;
    string date, item, amount;
    double correctAmount;

    char choice;

    income.setIncomeId(fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);

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

    income.setDate(dateConvertedToInt);
    income.setItem(item);
    income.setAmount(correctAmount);

    return income;
}

bool IncomesManager::less_than_key(const Income& struct1, const Income& struct2) {
    return (struct1.getDate() < struct2.getDate());
}

double IncomesManager::balanceOfTheIncomesInTheCurrentMonth() {
    Income income;
    AuxiliaryMethods auxiliaryMethods;
    int temporaryDateInInt = 0;
    string temporaryDateInString = "";
    incomesAmount = 0;
    int numberOfSelectedIncome = 1;

    vector <Income>::iterator itr = incomes.begin();

    sort(incomes.begin(), incomes.end(), less_than_key);

    system("cls");
    cout << "----------- BALANCE OF THE CURRENT MONTH (INCOMES) -----------" << endl;
    while (itr != incomes.end()) {
        temporaryDateInInt = itr -> getDate();

        if (auxiliaryMethods.checkingIfDateIsContainedInActuallyMonth(temporaryDateInInt) == true) {

            temporaryDateInString = auxiliaryMethods.convertIntToStringWithSeparatingCharacter(temporaryDateInInt);
            cout << numberOfSelectedIncome << " - " << temporaryDateInString << " - " << itr -> getItem() << " - " << itr -> getAmount() << endl;
            incomesAmount += itr -> getAmount();
            numberOfSelectedIncome++;
        }
        itr++;
        temporaryDateInInt = 0;
        temporaryDateInString = "";
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Amount of the incomes (of the current month): " << incomesAmount << endl;

    return 0;
}

double IncomesManager::balanceOfTheIncomesInThePreviousMonth() {
    Income income;
    AuxiliaryMethods auxiliaryMethods;
    int temporaryDateInInt = 0;
    string temporaryDateInString = "";
    incomesAmount = 0;
    int numberOfSelectedIncome = 1;

    vector <Income>::iterator itr = incomes.begin();

    sort(incomes.begin(), incomes.end(), less_than_key);

    system("cls");
    cout << "----------- BALANCE OF THE PREVIOUS MONTH (INCOMES) -----------" << endl;
    while (itr != incomes.end()) {
        temporaryDateInInt = itr -> getDate();

        if (auxiliaryMethods.checkingIfDateIsContainedInPreviousMonth(temporaryDateInInt) == true) {
            temporaryDateInString = auxiliaryMethods.convertIntToStringWithSeparatingCharacter(temporaryDateInInt);
            cout << numberOfSelectedIncome << " - " << temporaryDateInString << " - " << itr -> getItem() << " - " << itr -> getAmount() << endl;
            incomesAmount += itr -> getAmount();
            numberOfSelectedIncome++;
        }
        itr++;
        temporaryDateInInt = 0;
        temporaryDateInString = "";
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Amount of the incomes (of the previous month): " << incomesAmount << endl;

    return 0;
}

double IncomesManager::balanceOfTheIncomesInTheSelectedTime(string startingDate, string endDate) {
    Income income;
    AuxiliaryMethods auxiliaryMethods;
    int temporaryDateInInt = 0;
    string temporaryDateInString = "";
    incomesAmount = 0;
    int numberOfSelectedIncome = 1;

    vector <Income>::iterator itr = incomes.begin();

    sort(incomes.begin(), incomes.end(), less_than_key);

    cout << endl << endl << endl;

    cout << "----------- BALANCE OF THE SELECTED TIME (INCOMES) -----------" << endl;
    while (itr != incomes.end()) {
        temporaryDateInInt = itr -> getDate();

        if (auxiliaryMethods.checkingIfDateIsContainedInSelectedTime(temporaryDateInInt, startingDate, endDate) == true) {
            temporaryDateInString = auxiliaryMethods.convertIntToStringWithSeparatingCharacter(temporaryDateInInt);
            cout << numberOfSelectedIncome << " - " << temporaryDateInString << " - " << itr -> getItem() << " - " << itr -> getAmount() << endl;
            incomesAmount += itr -> getAmount();
            numberOfSelectedIncome++;
        }
        itr++;
        temporaryDateInInt = 0;
        temporaryDateInString = "";
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Amount of the incomes (of the previous month): " << incomesAmount << endl;

    return 0;
}

double IncomesManager::getIncomesAmount() {
    return incomesAmount;
}
