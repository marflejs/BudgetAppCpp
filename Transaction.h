#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int userId;
    int date;
    string item;
    int amount;

public:
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getUserId();
    int getDate() const;
    string getItem();
    int getAmount();
};

#endif
