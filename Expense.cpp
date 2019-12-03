#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    if (newExpenseId > 0)
        expenseId = newExpenseId;
}

int Expense::getExpenseId()
{
    return expenseId;
}
