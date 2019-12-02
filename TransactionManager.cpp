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

void TransactionManager::showBalanceOfCurrentMonth()
{
    string currentDate = AuxiliaryMethods::getCurrentDate();
    beginDate = AuxiliaryMethods::convertDateStringToInt(currentDate.replace(8, 2, "01"));
    endDate = AuxiliaryMethods::convertDateStringToInt(currentDate.replace(8, 2, "31"));

    showBalance();
}

void TransactionManager::showBalanceOfLastMonth()
{
    string currentDate = AuxiliaryMethods::getCurrentDate();
    //sposob na odczytanie samego miesiaca i podmiana go na poprzedni


    showBalance();
}

void TransactionManager::showBalanceOfChosenTimeRange()
{
    //a tutaj ma wczytywac od uzytkownika 2 dane - w poprawnym formacie - isDateOk?

    showBalance();
}

void TransactionManager::showBalance()
{
    int sumOfIncomes = 0;
    int sumOfExpenses = 0;

    for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        if (itr -> getDate() >= beginDate && itr -> getDate() <= endDate)
            balanceIncomes.push_back(*itr);

    for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        if (itr -> getDate() >= beginDate && itr -> getDate() <= endDate)
            balanceExpenses.push_back(*itr);

    sort(balanceIncomes.begin(), balanceIncomes.end(), less_than_key());
    sort(balanceExpenses.begin(), balanceExpenses.end(), less_than_key());

    //if puste poka¿ info ¿e brak i daj press any key - lae moze byc np. brak expenses i same incomes

    system("cls");

    cout << "----------------PRZYCHODY----------------" << endl;
    cout << "Data         Wartosc    Opis" << endl << endl;
    for(int i = 0; i < balanceIncomes.size(); i++)
    {
        cout << AuxiliaryMethods::convertDateFromIntToString(balanceIncomes[i].getDate()) << "   " <<
             AuxiliaryMethods::convertAmountIntToString(balanceIncomes[i].getAmount()) << "   " <<
             balanceIncomes[i].getItem() << endl;
    }

    cout << endl << endl << "----------------WYDATKI----------------" << endl;
    cout << "Data         Wartosc    Opis" << endl << endl;

    for(int i = 0; i < balanceExpenses.size(); i++)
    {
        cout << AuxiliaryMethods::convertDateFromIntToString(balanceExpenses[i].getDate()) << "   " <<
             AuxiliaryMethods::convertAmountIntToString(balanceExpenses[i].getAmount()) << "   " <<
             balanceExpenses[i].getItem() << endl;
    }

    //---------------liczenie--------------
    for(int i = 0; i < balanceIncomes.size(); i++)
    {
        sumOfIncomes += balanceIncomes[i].getAmount();
    }

    for(int i = 0; i < balanceExpenses.size(); i++)
    {
        sumOfExpenses += balanceExpenses[i].getAmount();
    }

    cout << endl << endl << "------------PODSUMOWANIE------------" << endl;
    cout << endl << "SUMA PRZYCHODOW: " << (float)sumOfIncomes/100.0 << endl;
    cout << "SUMA WYDATKOW: " << (float)sumOfExpenses/100.0 << endl << endl;
    cout << "BILANS OKRESU: " << (float)(sumOfIncomes - sumOfExpenses)/100.0 << endl << endl;

    system("pause");
}
