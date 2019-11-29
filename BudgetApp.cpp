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
        transactionManager = new TransactionManager(NAZWA_PLIKU_Z_ADRESATAMI, userManager.getIdOfLoggedInUser());
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
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
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
