#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    TransactionManager *transactionManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
public:
    BudgetApp(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : userManager(nazwaPlikuZUzytkownikami),
        NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
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
