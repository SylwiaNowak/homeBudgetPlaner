#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>
#include <ctime>
#include <conio.h> //getch();
//#include <iomanip> //stof(); z funkcji: static double convertStringToFloat(string myString);
#include <string>
#include <stdlib.h> //atof()

using namespace std;

class AuxiliaryMethods {
public:
    //static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    //static string konwerjsaIntNaString(int liczba);
    //static int konwersjaStringNaInt(string liczba);
    static string loadTheLine();
    char loadTheSign();
    char chooseOptionFromDateMenu();
    char chooseOptionFromRepairDateMenu();
    //int wczytajLiczbeCalkowita();
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
    double returnAmountInCorrectFormat(string amountToCheck);//PRZENIESIONE
    bool checkIfTheDateIsCorrect(string date);//PRZENIESIONE
    string loadActuallyDate();
    string loadActuallyMonth();
    string loadPreviousMonth(string actuallyDateToChange);
    static string convertDoubleToString(double myDouble);
    static double convertStringToDouble(string myString);
    int convertStringToInt(string myString);
    string convertIntToString(int myInt);
    //void sortFinancePositions();
    string convertStringDateToStringDateWithoutSeparatingCharakter(string myString);
    string convertIntToStringWithSeparatingCharacter(int myInt);
    bool checkingIfDateIsContainedInActuallyMonth(int temporaryDateInInt);
    bool checkingIfDateIsContainedInPreviousMonth(int temporaryDateInInt);
    bool checkingIfDateIsContainedInSelectedTime(int temporaryDateInInt, string startingDate, string endDate);
};

#endif
