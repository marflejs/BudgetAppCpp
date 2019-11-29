#include "TransactionManager.h"

Transaction TransactionManager::getNewTransactionData()
{
    Transaction transaction;

    transaction.setTransactionId((transactionsFile.getIdOfLastTransactionFromFile() + 1));
    transaction.setUserId(ID_OF_LOGGED_IN_USER);

    cout << "Podaj datê: ";
    transaction.setDate(AuxiliaryMethods::convertDateStringToInt(AuxiliaryMethods::getLine()));

    cout << "Podaj czego dotyczy: ";
    transaction.setItem(AuxiliaryMethods::getLine());
    transaction.setItem(AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(transaction.getItem()));

    cout << "Podaj kwotê: ";
    transaction.setAmount(AuxiliaryMethods::convertStringToFloat(AuxiliaryMethods::getLine()));

    return transaction;
}

void TransactionManager::showTransaction(Transaction transaction)
{
    cout << endl << "Id transakcji:                 " << transaction.getTransactionId() << endl;
    cout << "Data:               " << transaction.getDate() << endl;
    cout << "Dotyczy:           " << transaction.getItem() << endl;
    cout << "Kwota:     " << transaction.getAmount() << endl;
}

void TransactionManager::addTransaction()
{
    Transaction transaction;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    transaction = getNewTransactionData();

    transactions.push_back(transaction);

    if (transactionsFile.addTransactionToFile(transaction))
        cout << "Nowy adresat zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku" << endl;
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
