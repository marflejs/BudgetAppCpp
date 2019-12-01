#include "TransactionManager.h"

Transaction TransactionManager::getNewTransactionData()
{
    char choice;

    transaction.setTransactionId((transactionsFile.getIdOfLastTransactionFromFile() + 1)); //tu poprawic metode nadawania
    transaction.setUserId(ID_OF_LOGGED_IN_USER);

    do
    {
        cout << "Czy wprowadzic transakcje z data dzisiejsza[t/n]?" << endl;
        choice = AuxiliaryMethods::getChar();
        if(choice == 't')
        {
            transaction.setDate(AuxiliaryMethods::getCurrentDate());
        }
        if(choice == 'n')
        {
            do
            {
                cout << "Podaj date: ";
            } while (transaction.setDate(AuxiliaryMethods::getLine()) != true);
        }
    } while (choice != 't' && choice != 'n');

    cout << "Podaj czego dotyczy: ";
    transaction.setItem(AuxiliaryMethods::getLine());
    transaction.setItem(AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(transaction.getItem()));

    cout << "Podaj kwote: ";
    transaction.setAmount(AuxiliaryMethods::getLine());

    return transaction;
}

void TransactionManager::showTransaction(Transaction transaction)
{
    cout << endl << "Id transakcji:    " << transaction.getTransactionId() << endl;
    cout << "Data:         " << transaction.getDate() << endl;
    cout << "Dotyczy:      " << transaction.getItem() << endl;
    cout << "Kwota:        " << transaction.getAmount() << endl;
}

void TransactionManager::addTransaction()
{
    Transaction transaction;

    system("cls");
    cout << " >>> DODAWANIE NOWEJ TRANSAKCJI <<<" << endl << endl;

    transaction = getNewTransactionData();

    transactions.push_back(transaction);

    if (transactionsFile.addTransactionToFile(transaction))
        cout << "Nowa transakcja zostala dodana" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowej transakcji do pliku" << endl;

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
