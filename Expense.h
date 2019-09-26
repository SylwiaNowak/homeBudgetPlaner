#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    int date;
    string item;
    double amount;

public:
    Expense(int expenseId = 0, int userId = 0, int date = 0, string item = "", double amount = 0) {
        /*this -> expenseId = expenseId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;*/
    }
    // settery:
    void setExpenseId(int newExpenseId);
    void setUserId (int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    //gettery:
    int getExpenseId() const;
    int getUserId() const;
    int getDate() const;
    string getItem() const;
    double getAmount() const;
};

#endif
