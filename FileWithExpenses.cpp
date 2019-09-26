#include "FileWithExpenses.h"

bool FileWithExpenses::saveTheExpenseToTheFile(Expense expense) {
    CMarkup xml;
    AuxiliaryMethods auxiliaryMethods;

    bool fileExist = xml.Load("expenses.xml");

    if (!fileExist) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Expenses" );
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    //ZMIANA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    xml.AddElem("Date", auxiliaryMethods.convertIntToStringWithSeparatingCharacter(expense.getDate()));
    //
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(expense.getAmount()));

    xml.Save("expenses.xml");

    lastExpenseId++;

    return true;
}

vector <Expense> FileWithExpenses::loadExpensesBelongToLoggedInUserFromTheFile(int loggedInUserId) {
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    AuxiliaryMethods auxiliaryMethods;

    bool fileExist = xml.Load("expenses.xml");

    if (!fileExist) {
        cout << "No expenses exist." << endl;
        system("pause");
    } else {
        MCD_STR strXML = xml.GetDoc();
        xml.SetDoc(strXML);

        xml.FindElem(); // root Expenses element
        xml.IntoElem(); // inside Expenses

        while ( xml.FindElem("Expense") ) {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("UserId");
            expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            if (loggedInUserId == expense.getUserId()) {
                xml.FindElem( "Date" );
                MCD_STR strDate = xml.GetData();
                //ZMIANA
                expense.setDate(auxiliaryMethods.convertStringToInt(auxiliaryMethods.convertStringDateToStringDateWithoutSeparatingCharakter(strDate)));
                //
                //expense.setDate(strDate);
                xml.FindElem( "Item" );
                MCD_STR strItem = xml.GetData();
                expense.setItem(strItem);
                xml.FindElem("Amount");
                expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));

                expenses.push_back(expense);
                xml.OutOfElem();
            } else xml.OutOfElem();
        }
        lastExpenseId = expense.getExpenseId(); //CZY NAPEWNO TAK MA BYC???????????????
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}
