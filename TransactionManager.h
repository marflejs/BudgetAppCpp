#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

//#include "Transaction.h"
//#include "TransactionsFile.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class TransactionManager
{
    struct less_than_key
    {
        inline bool operator() (const Transaction& struct1, const Transaction& struct2)
        {
            return (struct1.getDate() < struct2.getDate());
        }
    };

    const int ID_OF_LOGGED_IN_USER;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
    //vector<Transaction> transactions;
    vector<Income> incomes;
    vector<Expense> expenses;

    IncomesFile incomesFile;
    ExpensesFile expensesFile;

    Transaction transaction;
    Income income;
    Expense expense;

    Income getNewIncomeData();
    Expense getNewExpenseData();

    vector<Income> balanceIncomes;
    vector<Expense> balanceExpenses;
    // showBalance(int beginDate, int endDate);
    void showBalance();
    int beginDate, endDate;

public:
    TransactionManager(string incomesFileName, string expensesFileName, int idOfLoggedInUser)
    : incomesFile(INCOMES_FILE_NAME), expensesFile(EXPENSES_FILE_NAME), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        incomes = incomesFile.getIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER),
        expenses = expensesFile.getExpensesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };

    void addIncome();
    void addExpense();

    void showBalanceOfCurrentMonth();
    void showBalanceOfLastMonth();
    void showBalanceOfChosenTimeRange();

};


#endif
