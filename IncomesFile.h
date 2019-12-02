#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "TransactionsFile.h"

using namespace std;

class IncomesFile : public TransactionsFile
{
public:
    IncomesFile(string fileName) : TransactionsFile(fileName) {
        idOfLastTransaction = 0;
    };

    bool addIncomeToFile(Income income);
    vector<Income> getIncomesOfLoggedInUserFromFile(int idOfLoggedUser);
    int getIdOfLastTransactionFromFile();
};

#endif
