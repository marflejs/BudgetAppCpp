#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    TransactionManager *transactionManager;
    const string TRANSACTIONS_FILE_NAME;
public:
    BudgetApp(string nazwaPlikuZUzytkownikami, string transactionsFileName)
        : userManager(nazwaPlikuZUzytkownikami),
        TRANSACTIONS_FILE_NAME(transactionsFileName)
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
    void addTransaction();
    bool isUserLoggedIn();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();

    void showBalanceOfCurrentMonth();
    void showBalanceOfLastMonth();
    void showBalanceOfChosenTimeRange();
};

#endif
