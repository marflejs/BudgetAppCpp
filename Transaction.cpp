#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

void Transaction::setUserId(int newUserId)
{
    if (newUserId > 0)
        userId = newUserId;
}

void Transaction::setDate(string newDate)
{
    if(DateManager::isDateOk)
        date = DateManager::convertDateStringToInt(newDate);
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
