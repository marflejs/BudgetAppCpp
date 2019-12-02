#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    TransactionManager *transactionManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;
public:
    BudgetApp(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName),
        INCOMES_FILE_NAME(incomesFileName),
        EXPENSES_FILE_NAME(expensesFileName)
    {
        transactionManager = NULL;
    };

    ~BudgetApp()
    {
        delete transactionManager;
        transactionManager = NULL;
    };

    void signInUser();
    void logInUser();
    void changePasswordOfLoggedInUser();
    void logOffUser();
    void addIncome();
    void addExpense();
    bool isUserLoggedIn();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();

    void showBalanceOfCurrentMonth();
    void showBalanceOfLastMonth();
    void showBalanceOfChosenTimeRange();
};

#endif
