#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>

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

    Income income;
    vector<Income> incomes;
    IncomesFile incomesFile;
    Income getNewIncomeData();
    vector<Income> balanceIncomes;

    Expense expense;
    vector<Expense> expenses;
    ExpensesFile expensesFile;
    Expense getNewExpenseData();
    vector<Expense> balanceExpenses;

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
