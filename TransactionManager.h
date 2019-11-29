#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>

#include "Transaction.h"
#include "TransactionsFile.h"

using namespace std;

class TransactionManager
{
    const int ID_OF_LOGGED_IN_USER;
    const string TRANSACTIONS_FILE_NAME;
    const string TEMPORARY_TRANSACTIONS_FILE_NAME;
    vector<Transaction> transactions;
    TransactionsFile transactionsFile;

    Transaction getNewTransactionData();
    void showTransaction(Transaction transaction);
    float calculateBalanceSheetTotal();
    void sortTransactionsByDate();

public:
    TransactionManager(string transactionsFileName, int idOfLoggedInUser)
    : transactionsFile(transactionsFileName), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        transactions = transactionsFile.getTransactionsOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };
    void addTransaction();
    void showBalanceOfCurrentMonth();
    void showBalanceOfLastMonth();
    void showBalanceOfChosenTimeRange();

};


#endif
