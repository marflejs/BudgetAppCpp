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
        transactionManager = new TransactionManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getIdOfLoggedInUser());
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

void BudgetApp::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager -> addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void BudgetApp::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager -> addExpense();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac" << endl;
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
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
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
