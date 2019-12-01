#include <iostream>

#include "BudgetApp.h"
#include "Markup.h"

int main()
{
    BudgetApp budgetApp("Users.xml", "Transactions.xml");
    char choice;
    while(true)
    {
        if (!budgetApp.isUserLoggedIn())
        {
            choice = budgetApp.chooseOptionFromMainMenu();
            switch(choice)
            {
            case '1':
                budgetApp.signInUser();
                break;
            case '2':
                budgetApp.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = budgetApp.chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                //budgetApp.addIncome();
                budgetApp.addTransaction();
                break;
            case '2':
                //budgetApp.addExpense();
                budgetApp.addTransaction();
                break;
            case '3':
                budgetApp.showBalanceOfCurrentMonth();
                break;
            case '4':
                budgetApp.showBalanceOfLastMonth();
                break;
            case '5':
                budgetApp.showBalanceOfChosenTimeRange();
                break;
            case '6':
                budgetApp.changePasswordOfLoggedInUser();
                break;
            case '7':
                budgetApp.logOffUser();
                break;
            }
        }
    }
    return 0;
}

