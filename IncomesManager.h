#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include <windows.h>
#include <algorithm> // funkcja sort()
#include <sstream>
#include <string.h>
#include <iomanip>

//#include "User.h"

#include "Income.h"
#include "AuxiliaryMethods.h"
//#include "UserManager.h"
#include "FileWithIncomes.h"

using namespace std;

class IncomesManager {
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;
    //AuxiliaryMethods auxiliaryMethods;


    Income inputDataOfTheNewIncome();
//void wyswietlDaneAdresata(Adresat adresat);
//string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
//int podajIdWybranegoAdresata();
//int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsunietegoAdresata, int idOstatniegoAdresata);
//char wybierzOpcjeZMenuEdycja();
//void zaktualizujDaneEdytowanegoAdresata(Adresat adresat);
//void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);

    //int getNumberOfDays(int month, int year);
    bool static less_than_key(const Income& struct1, const Income& struct2);

public:
    IncomesManager (string nameOfFileWithIncomes, int loggedInUserId)
    : fileWithIncomes(nameOfFileWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
    incomes = fileWithIncomes.loadIncomesBelongToLoggedInUserFromTheFile(LOGGED_IN_USER_ID);
    //cout << "USER ID: " << LOGGED_IN_USER_ID << endl; TEST
    //system("pause"); TEST
    }

    void addIncome();
    double balanceOfTheIncomesInTheCurrentMonth();
    double balanceOfTheIncomesInThePreviousMonth();
    double balanceOfTheIncomesInTheSelectedTime();
//void wyszukajAdresatowPoImieniu();
//void wyszukajAdresatowPoNazwisku();
//void wyswietlWszystkichAdresatow();
//int usunAdresata();
//void edytujAdresata();
    //int setIncomeIdOfTheNewIncomeForTheLoggedInUser();
};

#endif
