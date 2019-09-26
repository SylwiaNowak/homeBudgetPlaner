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
//string nazwaTymczasowegoPlikuZAdresatami;
    int lastIncomeId;

//bool czyPlikJestPusty(fstream &plikTekstowy); PRZENIESIONE DO INNEGO NAGLOWKA
//string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);

//Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
//int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
//int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
//void usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem);
//void zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);

public:
    FileWithIncomes(string nameOfFileWithIncomes) : NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes) {
//nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
        lastIncomeId = 0;
    };
    bool saveTheIncomeToTheFile(Income income); //bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Income> loadIncomesBelongToLoggedInUserFromTheFile(int loggedInUserId);
    int getLastIncomeId();
//void usunWybranegoAdresataZPliku(int idUsunietegoAdresata); // optymalizacja
//int pobierzZPlikuIdOstatniegoAdresata();
//void edytujAdresataWPliku(Adresat adresat);// optymalizacja
};

#endif
