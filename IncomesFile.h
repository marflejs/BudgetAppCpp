#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesFile
{
public:
    IncomesFile(string fileName){
        int idOfLastTransaction = 0;
    };

    bool addIncomeToFile(Income income);
    vector<Income> getIncomesOfLoggedInUserFromFile(int idOfLoggedUser);
    int getIdOfLastTransactionFromFile();
};

#endif
