#include "Expense.h"

// settery:
void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId > 0)
    expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId) {
    if (newUserId > 0)
    userId = newUserId;
}

void Expense::setDate(int newDate) {
    date = newDate;
}

void Expense::setItem(string newItem) {
    item = newItem;
}

void Expense::setAmount(double newAmount) {
    amount = newAmount;
}

//gettery:
int Expense::getExpenseId() const {
    return expenseId;
}

int Expense::getUserId() const {
    return userId;
}

int Expense::getDate() const {
    return date;
}

string Expense::getItem() const {
    return item;
}

double Expense::getAmount() const {
    return amount;
}
