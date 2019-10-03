#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>
#include <ctime>
#include <conio.h> //getch()
#include <string>
#include <stdlib.h> //atof()

using namespace std;

class AuxiliaryMethods {
public:
    static string loadTheLine();
    char loadTheSign();
    char chooseOptionFromDateMenu();
    char chooseOptionFromRepairDateMenu();
    double returnAmountInCorrectFormat(string amountToCheck);
    bool checkIfTheDateIsCorrect(string date);
    string loadActuallyDate();
    string loadActuallyMonth();
    string loadPreviousMonth(string actuallyDateToChange);
    static string convertDoubleToString(double myDouble);
    static double convertStringToDouble(string myString);
    int convertStringToInt(string myString);
    string convertIntToString(int myInt);
    string convertStringDateToStringDateWithoutSeparatingCharakter(string myString);
    string convertIntToStringWithSeparatingCharacter(int myInt);
    bool checkingIfDateIsContainedInActuallyMonth(int temporaryDateInInt);
    bool checkingIfDateIsContainedInPreviousMonth(int temporaryDateInInt);
    bool checkingIfDateIsContainedInSelectedTime(int temporaryDateInInt, string startingDate, string endDate);
};

#endif
