#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId > 0)
        incomeId = newIncomeId;
}

int Income::getIncomeId()
{
    return incomeId;
}
