#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadTheLine() {
    string entry = "";
    getline(cin, entry);
    return entry;
}

char AuxiliaryMethods::loadTheSign() {
    string entry = "";
    char sign  = {0};

    while (true) {
        getline(cin, entry);

        if (entry.length() == 1) {
            sign = entry[0];
            break;
        }
        cout << "It is not the single sign. Please enter again." << endl;
    }
    return sign;
}

char AuxiliaryMethods::chooseOptionFromDateMenu() {
    char choice;

    system("cls");
    cout << "Give date in format: rrrr-mm-dd: " << endl;
    cout << "Choose format of the date: " << endl;
    cout << "1 - today" << endl;
    cout << "2 - another date" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadTheSign();

    return choice;
}

char AuxiliaryMethods::chooseOptionFromRepairDateMenu() {
    char choice;

    system("cls");
    cout << "Choose option: " << endl;
    cout << "1 - try again" << endl;
    cout << "2 - exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadTheSign();

    return choice;
}

double AuxiliaryMethods::returnAmountInCorrectFormat(string amountToCheck) {
    string amountInStringFormatAfterChecking = "";
    double amountAfterChecking = 0.00;

    for (int i = 0; i < amountToCheck.length(); i++) {
        if (amountToCheck[i] == ',') {
            amountToCheck[i] = '.';
            amountInStringFormatAfterChecking += amountToCheck[i];
        } else
            amountInStringFormatAfterChecking += amountToCheck[i];
    }

    amountAfterChecking = convertStringToDouble(amountInStringFormatAfterChecking);

    return amountAfterChecking;
}

bool AuxiliaryMethods::checkIfTheDateIsCorrect(string date) {
    string actuallyDate = loadActuallyDate();

    int yearInInt, monthInInt, dayInInt;
    int actuallyYearInInt, actuallyMonthInInt, actuallyDayInInt;

    string yearInString (date, 0, 4);
    string monthInString (date, 5, 2);
    string dayInString (date, 8, 2);

    string actuallyYearInString (actuallyDate, 0, 4);
    string actuallyMonthInString (actuallyDate, 5, 2);
    string actuallyDayInString (actuallyDate, 8, 2);

    yearInInt = convertStringToInt(yearInString);
    monthInInt = convertStringToInt(monthInString);
    dayInInt = convertStringToInt(dayInString);

    actuallyYearInInt = convertStringToInt(actuallyYearInString);
    actuallyMonthInInt = convertStringToInt(actuallyMonthInString);
    actuallyDayInInt = convertStringToInt(actuallyDayInString);

    if (date.length() != 10)
        return false;

    for (int i = 0; i < date.length(); i++) {
        if (date[4] != '-' && date[7] != '-')
            return false;
    }

    if (yearInInt < 2000 || yearInInt > actuallyYearInInt)
        return false;

    if (yearInInt == actuallyYearInInt && monthInInt > actuallyMonthInInt)
        return false;

    if (monthInString=="01" || monthInString=="03" || monthInString=="05" || monthInString=="07" || monthInString=="08" || monthInString=="10" || monthInString=="12") {
        if (date[8] == '0' && date[9] >= '1' && date[9] <= '9')
            return true;
        if ((date[8] == '1' || date[8] == '2') && date[9] >= '0' && date[9] <= '9')
            return true;
        if (date[8] == '3' && (date[9] == '0' || date[9] == '1'))
            return true;
        else
            return false;
    } else if (monthInString=="02") {
        if ((yearInInt%4 == 0 && yearInInt%100 != 0) || yearInInt%400 == 0) {
            if (date[8] == '0' && date[9] >= '1' && date[9] <= '9')
                return true;
            else if ((date[8] == '1' || date[8] == '2') && date[9] >= '0' && date[9] <= '9')
                return true;
            else
                return false;
        } else {
            if (date[8] == '0' && date[9] >= '1' && date[9] <= '9')
                return true;
            else if (date[8] == '1' && date[9] >= '0' && date[9] <= '9')
                return true;
            else if (date[8] == '2' && date[9] >= '0' && date[9] <= '8')
                return true;
            else
                return false;
        }
    } else {
        if (date[8] == '0' && date[9] >= '1' && date[9] <= '9')
            return true;
        else if ((date[8] == '1' || date[8] == '2') && date[9] >= '0' && date[9] <= '9')
            return true;
        else if (date[8] == '3' && date[9] == '0')
            return true;
        else
            return false;
    }
}

string AuxiliaryMethods::loadActuallyDate() {
    time_t czas;
    struct tm * data;
    char dzisiejsza_data[ 80 ];

    time( & czas );
    data = localtime( & czas );

    strftime( dzisiejsza_data, 80, "%Y-%m-%d", data );

    //getch(); //nie czeka na klawisz enter

    return dzisiejsza_data;
}

string AuxiliaryMethods::loadActuallyMonth() {
    time_t czas;
    struct tm * miesiac;
    char aktualny_miesiac[80];

    time( & czas );
    miesiac = localtime( & czas );

    strftime( aktualny_miesiac, 80, "%Y-%m", miesiac );

    //getch(); //nie czeka na klawisz enter

    return aktualny_miesiac;
}

string AuxiliaryMethods::loadPreviousMonth (string actuallyDateToChange) {

    string actuallyYearInString (actuallyDateToChange, 0, 4);
    string actuallyMonthInString (actuallyDateToChange, 4, 2);

    int yearInIntFromPreviousMonth = 0, monthInIntFromPreviousMonth = 0;

    string dateFromPreviousMonth = "";

    if(actuallyMonthInString == "01") {
        monthInIntFromPreviousMonth = 12;
        yearInIntFromPreviousMonth = convertStringToInt(actuallyYearInString) - 1 ;

        dateFromPreviousMonth = convertIntToString(yearInIntFromPreviousMonth) + convertIntToString(monthInIntFromPreviousMonth);
        return dateFromPreviousMonth;
    }

    else {
        monthInIntFromPreviousMonth = convertStringToInt(actuallyMonthInString) - 1;

        if (monthInIntFromPreviousMonth == 1 || monthInIntFromPreviousMonth == 2 || monthInIntFromPreviousMonth == 3 ||
                monthInIntFromPreviousMonth == 4 || monthInIntFromPreviousMonth == 5 || monthInIntFromPreviousMonth == 6 ||
                monthInIntFromPreviousMonth == 7 || monthInIntFromPreviousMonth == 8 || monthInIntFromPreviousMonth == 9) {
            dateFromPreviousMonth = actuallyYearInString + "0" + convertIntToString(monthInIntFromPreviousMonth);
        } else dateFromPreviousMonth = actuallyYearInString + convertIntToString(monthInIntFromPreviousMonth);

        return dateFromPreviousMonth;
    }
}

string AuxiliaryMethods::convertDoubleToString(double myDouble) {
    ostringstream ss;
    ss << myDouble;
    string s(ss.str());

    return s;
}

double AuxiliaryMethods::convertStringToDouble(string myString) {
    double v = atof(myString.c_str());

    return v;
}

int AuxiliaryMethods::convertStringToInt(string myString) {
    int b = atoi(myString.c_str());

    return b;
}

string AuxiliaryMethods::convertIntToString(int myInt) {
    ostringstream ss;
    ss << myInt;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertStringDateToStringDateWithoutSeparatingCharakter(string myString) {
    string dateWithoutSeparatingCharakter = "";

    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] != '-') {
            dateWithoutSeparatingCharakter += myString[i];
        }
    }
    return dateWithoutSeparatingCharakter;
}

string AuxiliaryMethods::convertIntToStringWithSeparatingCharacter(int myInt) {
    string myString = "";
    string myStringWithSeparatingCharacters = "";
    myString = convertIntToString(myInt);

    for (int i = 0; i < myString.length(); i++) {
        if ((i == 4) || (i == 6)) {
            myStringWithSeparatingCharacters += '-';
        }
        myStringWithSeparatingCharacters += myString[i];
    }
    return myStringWithSeparatingCharacters;
}

bool AuxiliaryMethods::checkingIfDateIsContainedInActuallyMonth(int temporaryDateInInt) {
    string temporaryDateInString = "";
    string actuallyMonth = "";
    temporaryDateInString = convertIntToString(temporaryDateInInt);
    actuallyMonth = convertStringDateToStringDateWithoutSeparatingCharakter(loadActuallyMonth());

    for (int i = 0; i < 6; i++) {
        if (temporaryDateInString[i] != actuallyMonth[i]) {
            return false;
        }
    }
    return true;
}

bool AuxiliaryMethods::checkingIfDateIsContainedInPreviousMonth(int temporaryDateInInt) {
    string temporaryDateInString = "";
    string previousMonth = "";
    string actuallyDateWithoutSeparatingCharakter = "";
    actuallyDateWithoutSeparatingCharakter = convertStringDateToStringDateWithoutSeparatingCharakter(loadActuallyDate());
    temporaryDateInString = convertIntToString(temporaryDateInInt);
    previousMonth = loadPreviousMonth(actuallyDateWithoutSeparatingCharakter);

    for (int i = 0; i < 6; i++) {
        if (temporaryDateInString[i] != previousMonth[i]) {
            return false;
        }
    }
    return true;
}

bool AuxiliaryMethods::checkingIfDateIsContainedInSelectedTime(int temporaryDateInInt, string startingDate, string endDate) {
    int temporaryStartingDateInInt = 0;
    int temporaryEndDateInInt = 0;
    temporaryStartingDateInInt = convertStringToInt(convertStringDateToStringDateWithoutSeparatingCharakter(startingDate));
    temporaryEndDateInInt = convertStringToInt(convertStringDateToStringDateWithoutSeparatingCharakter(endDate));

    if (temporaryDateInInt < temporaryStartingDateInInt) {
        return false;
    } else if (temporaryDateInInt > temporaryEndDateInInt) {
        return false;
    } else return true;
}
