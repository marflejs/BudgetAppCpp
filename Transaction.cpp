#include "Transaction.h"

void Transaction::setTransactionId(int newTransactionId)
{
    if (newTransactionId > 0)
        transactionId = newTransactionId;
}

void Transaction::setUserId(int newUserId)
{
    if (newUserId > 0)
        userId = newUserId;
}

void Transaction::setDate(int newDate)
{
    date = newDate;
}

void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(float newAmount)
{
    amount = newAmount;
}

int Transaction::getTransactionId()
{
    return transactionId;
}

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getDate()
{
    return date;
}

string Transaction::getItem()
{
    return item;
}

float Transaction::getAmount()
{
    return amount;
}
