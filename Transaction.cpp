#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include <cstdio>

void Transaction::setUserId(int newUserId)
{
    if (newUserId > 0)
        userId = newUserId;
}

void Transaction::setDate(string newDate)
{
    if(AuxiliaryMethods::isDateOk)
        date = AuxiliaryMethods::convertDateStringToInt(newDate);
}

void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(string newAmount)
{
    amount = AuxiliaryMethods::convertAmountStringToInt(newAmount);
}

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getDate() const
{
    return date;
}

string Transaction::getItem()
{
    return item;
}

int Transaction::getAmount()
{
    return amount;
}
