#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include <cstdio>

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

void Transaction::setDate(string newDate)
{
    int newYear, newMonth, newDay;
    sscanf(newDate.c_str(), "%4d-%2d-%2d", &newYear, &newMonth, &newDay);

    if(newYear > 2000 &&
        newMonth > 0 &&
        newMonth < 13 &&
        newDay > 0 &&
        newDay <= AuxiliaryMethods::calculateNumberOfDaysInMonth(newMonth, newYear))
        date = AuxiliaryMethods::convertDateStringToInt(newDate);
    else
    {
        cout << "Niepoprawna data";
        exit(0);
    }
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
