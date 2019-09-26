#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    int date;
    string item;
    double amount;

public:
    /*Income(int incomeId = 0, int userId = 0, int date = 0, string item = "", double amount = 0) {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }*/
    Income(int incomeId = 0, int userId = 0, int date = 0, string item = "", double amount = 0) {}
    //MyStruct(int k, const std::string& s) : key(k), stringValue(s) {}
    // settery:
    void setIncomeId(int newIncomeId);
    void setUserId (int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    //gettery:
    int getIncomeId() const;
    int getUserId() const;
    int getDate() const;
    string getItem() const;
    double getAmount() const;
};

#endif
