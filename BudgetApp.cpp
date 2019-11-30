#include "BudgetApp.h"
#include "AuxiliaryMethods.h"

using namespace std;

void BudgetApp::signInUser()
{
    userManager.signInUser();
}

void BudgetApp::logInUser()
{
    userManager.logInUser();
    if (userManager.isUserLoggedIn())
    {
        transactionManager = new TransactionManager(TRANSACTIONS_FILE_NAME, userManager.getIdOfLoggedInUser());
    }
}

void BudgetApp::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}

void BudgetApp::logOffUser()
{
    userManager.logOffUser();
    delete transactionManager;
    transactionManager = NULL;
}

void BudgetApp::addTransaction()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager -> addTransaction();
    }
    else
    {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

bool BudgetApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

char BudgetApp::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

char BudgetApp::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj transakcje" << endl;
    cout << "2. Dodaj transakcje" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

void BudgetApp::showBalanceOfCurrentMonth()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager -> showBalanceOfCurrentMonth();
    }
}

void BudgetApp::showBalanceOfLastMonth()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager -> showBalanceOfLastMonth();
    }
}

void BudgetApp::showBalanceOfChosenTimeRange()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager -> showBalanceOfChosenTimeRange();
    }
}
