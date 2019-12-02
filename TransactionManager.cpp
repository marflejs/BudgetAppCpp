#include "TransactionManager.h"

Income TransactionManager::getNewIncomeData()
{
    char choice;

    income.setIncomeId((incomesFile.getIdOfLastTransactionFromFile() + 1)); //tu poprawic metode nadawania
    income.setUserId(ID_OF_LOGGED_IN_USER);

    do
    {
        cout << "Czy wprowadzic przychod z data dzisiejsza[t/n]?" << endl;
        choice = AuxiliaryMethods::getChar();
        if(choice == 't')
        {
            income.setDate(AuxiliaryMethods::getCurrentDate());
        }
        if(choice == 'n')
        {
            do
            {
                cout << "Podaj date: ";
            } while (income.setDate(AuxiliaryMethods::getLine()) != true);
        }
    } while (choice != 't' && choice != 'n');

    cout << "Podaj czego dotyczy przychod: ";
    income.setItem(AuxiliaryMethods::getLine());
    income.setItem(AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(income.getItem()));

    cout << "Podaj kwote: ";
    income.setAmount(AuxiliaryMethods::getLine());

    return income;
}

Expense TransactionManager::getNewExpenseData()
{
    char choice;

    expense.setExpenseId((expensesFile.getIdOfLastTransactionFromFile() + 1)); //tu poprawic metode nadawania
    expense.setUserId(ID_OF_LOGGED_IN_USER);

    do
    {
        cout << "Czy wprowadzic wydatek z data dzisiejsza[t/n]?" << endl;
        choice = AuxiliaryMethods::getChar();
        if(choice == 't')
        {
            expense.setDate(AuxiliaryMethods::getCurrentDate());
        }
        if(choice == 'n')
        {
            do
            {
                cout << "Podaj date: ";
            } while (expense.setDate(AuxiliaryMethods::getLine()) != true);
        }
    } while (choice != 't' && choice != 'n');

    cout << "Podaj czego dotyczy wydatek: ";
    expense.setItem(AuxiliaryMethods::getLine());
    expense.setItem(AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(expense.getItem()));

    cout << "Podaj kwote: ";
    expense.setAmount(AuxiliaryMethods::getLine());

    return expense;
}
/*
void TransactionManager::showTransaction(Transaction transaction)
{
    cout << endl << "Id transakcji:    " << transaction.getTransactionId() << endl;
    cout << "Data:         " << transaction.getDate() << endl;
    cout << "Dotyczy:      " << transaction.getItem() << endl;
    cout << "Kwota:        " << transaction.getAmount() << endl;
}
*/
void TransactionManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;

    income = getNewIncomeData();

    incomes.push_back(income);

    if (incomesFile.addIncomeToFile(income))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku" << endl;

    system("pause");
}

void TransactionManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;

    expense = getNewExpenseData();

    expenses.push_back(expense);

    if (expensesFile.addExpenseToFile(expense))
        cout << "Nowy wydatek zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku" << endl;

    system("pause");
}

float TransactionManager::calculateBalanceSheetTotal()
{
    cout << "policzono sume" << endl;
    return 1.0;
}

void TransactionManager::sortTransactionsByDate()
{
    cout << "posortowano" << endl;
}

void TransactionManager::showBalanceOfCurrentMonth()
{
    cout << "Balance of currenth month" << endl;
    system("pause");
}

void TransactionManager::showBalanceOfLastMonth()
{
    cout << "Balance of currenth month" << endl;
    system("pause");
}

void TransactionManager::showBalanceOfChosenTimeRange()
{
    cout << "Balance of currenth month" << endl;
    system("pause");
}
