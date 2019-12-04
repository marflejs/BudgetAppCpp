#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesFile
{
public:
    ExpensesFile(string fileName){
        int idOfLastTransaction = 0;
    };

    bool addExpenseToFile(Expense expense);
    vector<Expense> getExpensesOfLoggedInUserFromFile(int idOfLoggedUser);
    int getIdOfLastTransactionFromFile();
};

#endif

