#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int transactionId;
    int userId;
    int date;
    string item;
    int amount;

public:
    void setTransactionId(int newTransactionId);
    void setUserId(int newUserId);
    bool setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getTransactionId();
    int getUserId();
    int getDate();
    string getItem();
    int getAmount();
};

#endif
