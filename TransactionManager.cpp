#include "TransactionManager.h"

Income TransactionManager::getNewIncomeData()
{
    char choice;
    string newDate = "";

    income.setIncomeId((incomesFile.getIdOfLastTransactionFromFile() + 1));
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
                newDate = AuxiliaryMethods::getLine();
                income.setDate(newDate);
            } while (AuxiliaryMethods::isDateOk(newDate) != true);
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

    expense.setExpenseId((expensesFile.getIdOfLastTransactionFromFile() + 1));
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
                expense.setDate(AuxiliaryMethods::getLine());
            } while (AuxiliaryMethods::isDateOk(AuxiliaryMethods::getLine()) != true);
        }
    } while (choice != 't' && choice != 'n');

    cout << "Podaj czego dotyczy wydatek: ";
    expense.setItem(AuxiliaryMethods::getLine());
    expense.setItem(AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(expense.getItem()));

    cout << "Podaj kwote: ";
    expense.setAmount(AuxiliaryMethods::getLine());

    return expense;
}

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

    int lastMonth = AuxiliaryMethods::convertStringToInt(currentDate.substr(5, 2)) - 1;

    int yearOfLastMonth = AuxiliaryMethods::convertStringToInt(currentDate.substr(0, 4));

    if(lastMonth == 0)
    {
        lastMonth = 12;
        yearOfLastMonth -= 1;
    }

    beginDate = 10000 * yearOfLastMonth + 100 * lastMonth + 1;
    endDate = beginDate + 30;

    showBalance();
}

void TransactionManager::showBalanceOfChosenTimeRange()
{
    string inputDate = "";

    do
    {
        cout << "Podaj date poczatkowa: ";
        inputDate = AuxiliaryMethods::getLine();
    } while (AuxiliaryMethods::isDateOk(inputDate) != true);

    beginDate = AuxiliaryMethods::convertDateStringToInt(inputDate);

    do
    {
        cout << "Podaj date koncowa: ";
        inputDate = AuxiliaryMethods::getLine();
    } while (AuxiliaryMethods::isDateOk(inputDate) != true);

    endDate = AuxiliaryMethods::convertDateStringToInt(inputDate);

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

    balanceIncomes.clear();
    balanceExpenses.clear();

    system("pause");
}
