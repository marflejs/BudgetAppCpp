#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H

#include <iostream>

using namespace std;

class TransactionsFile
{
    const string FILE_NAME;
protected:
    int idOfLastTransaction;

public:
    TransactionsFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName()
    {
        return FILE_NAME;
    }

};

#endif

