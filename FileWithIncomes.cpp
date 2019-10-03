#include "FileWithIncomes.h"

bool FileWithIncomes::saveTheIncomeToTheFile(Income income) {
    CMarkup xml;
    AuxiliaryMethods auxiliaryMethods;

    bool fileExist = xml.Load("incomes.xml");

    if (!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Incomes" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    //ZMIANA!!!
    xml.AddElem("Date", auxiliaryMethods.convertIntToStringWithSeparatingCharacter(income.getDate()));
    //
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(income.getAmount()));

    xml.Save("incomes.xml");

    lastIncomeId++;

    return true;
}

vector <Income> FileWithIncomes::loadIncomesBelongToLoggedInUserFromTheFile(int loggedInUserId) {
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    AuxiliaryMethods auxiliaryMethods;

    bool fileExist = xml.Load("incomes.xml");

    if (!fileExist) {
        cout << "No incomes exist." << endl;
        system("pause");
    } else {
        MCD_STR strXML = xml.GetDoc();
        xml.SetDoc(strXML);

        xml.FindElem(); // root Incomes element
        xml.IntoElem(); // inside Incomes

        while ( xml.FindElem("Income") ) {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("UserId");
            income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            if (loggedInUserId == income.getUserId()) {
                xml.FindElem( "Date" );
                MCD_STR strDate = xml.GetData();
                //ZMIANA
                income.setDate(auxiliaryMethods.convertStringToInt(auxiliaryMethods.convertStringDateToStringDateWithoutSeparatingCharakter(strDate)));
                //income.setDate(strDate);
                xml.FindElem( "Item" );
                MCD_STR strItem = xml.GetData();
                income.setItem(strItem);
                xml.FindElem("Amount");
                income.setAmount(atof(MCD_2PCSZ(xml.GetData())));

                incomes.push_back(income);
                xml.OutOfElem();
            } else xml.OutOfElem();
        }
        lastIncomeId = income.getIncomeId();
    }
    return incomes;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
}
