#include "Income.h"
#include "AuxiliaryMethods.h"
#include <cstdio>

void Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId > 0)
        incomeId = newIncomeId;
}

int Income::getIncomeId()
{
    return incomeId;
}
