#include "Transaction.h"
#include "AuxiliaryMethods.h"
#include <cstdio>

void Transaction::setUserId(int newUserId)
{
    if (newUserId > 0)
        userId = newUserId;
}

bool Transaction::setDate(string newDate)
{
    bool isDateOk = true;
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
        cout << "Niepoprawna data. WprowadŸ ponownie" << endl;
        isDateOk = false;
    }

    return isDateOk;
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

int Transaction::getDate()
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
