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
    float amount;

public:
    void setTransactionId(int newTransactionId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getTransactionId();
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
