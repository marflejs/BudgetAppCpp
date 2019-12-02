#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "TransactionsFile.h"

using namespace std;

class ExpensesFile : public TransactionsFile
{
public:
    ExpensesFile(string fileName) : TransactionsFile(fileName) {
        idOfLastTransaction = 0;
    };

    bool addExpenseToFile(Expense expense);
    vector<Expense> getExpensesOfLoggedInUserFromFile(int idOfLoggedUser);
    int getIdOfLastTransactionFromFile();
};

#endif

