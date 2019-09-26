#include "Income.h"

// settery:
void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId > 0)
    incomeId = newIncomeId;
}

void Income::setUserId(int newUserId) {
    if (newUserId > 0)
    userId = newUserId;
}

void Income::setDate(int newDate) {
    date = newDate;
}

void Income::setItem(string newItem) {
    item = newItem;
}

void Income::setAmount(double newAmount) {
    amount = newAmount;
}

//gettery:
int Income::getIncomeId() const {
    return incomeId;
}

int Income::getUserId() const {
    return userId;
}

int Income::getDate() const {
    return date;
}

string Income::getItem() const {
    return item;
}

double Income::getAmount() const {
    return amount;
}
