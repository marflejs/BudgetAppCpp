#include "Expense.h"
#include "AuxiliaryMethods.h"
#include <cstdio>

void Expense::setExpenseId(int newExpenseId)
{
    if (newExpenseId > 0)
        expenseId = newExpenseId;
}

int Expense::getExpenseId()
{
    return expenseId;
}
