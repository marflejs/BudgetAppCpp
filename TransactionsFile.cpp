#include "TransactionsFile.h"
#include "Markup.h"

bool TransactionsFile::addTransactionToFile(Transaction transaction)
{
    CMarkup xml_transactions;

    bool transactionsFileExists = xml_transactions.Load( "transactions.xml" );

    if (!transactionsFileExists)
    {
        xml_transactions.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_transactions.AddElem("Transactions");
    }

    xml_transactions.FindElem();
    xml_transactions.IntoElem();
    xml_transactions.AddElem("Transaction");
    xml_transactions.IntoElem();
    xml_transactions.AddElem("TransactionId", transaction.getTransactionId());
    xml_transactions.AddElem("UserId", transaction.getUserId());
    xml_transactions.AddElem("Date", AuxiliaryMethods::convertDateFromIntToString(transaction.getDate()));
    xml_transactions.AddElem("Item", transaction.getItem());
    xml_transactions.AddElem("Amount", transaction.getAmount());

    xml_transactions.Save("transactions.xml");

    return true;    //do poprawy, uwzglednic spr czy plik good
}

vector<Transaction> TransactionsFile::getTransactionsOfLoggedInUserFromFile(int idOfLoggedUser)
{
    Transaction transaction;
    vector<Transaction> transactions;
    string informationFromFile = "";
    int numberOfInformationFromFile = 1;

    CMarkup xml_transactions;;

    bool transactionsFileExists = xml_transactions.Load( "transactions.xml" );
    xml_transactions.FindElem();
    xml_transactions.IntoElem();

    while (xml_transactions.FindElem("Transaction"))
    {
        xml_transactions.FindChildElem("UserId");

        if (atoi(MCD_2PCSZ(xml_transactions.GetChildData())) == idOfLoggedUser)
        {
            xml_transactions.ResetChildPos(); //child byl na user id, a chce od poczatku - od transaction id

            while (xml_transactions.FindChildElem())
            {
                informationFromFile = xml_transactions.GetChildData();

                switch(numberOfInformationFromFile)
                {
                case 1:
                    transaction.setTransactionId(atoi(informationFromFile.c_str()));
                    break;
                case 2:
                    transaction.setUserId(atoi(informationFromFile.c_str()));
                    break;
                case 3:
                    transaction.setDate(informationFromFile);
                    //bo w pliku siedzi jako string; teraz setDate dostanie stringa - jak przy inpucie
                    break;
                case 4:
                    transaction.setItem(informationFromFile);
                    break;
                case 5:
                    transaction.setAmount(atoi(informationFromFile.c_str()));
                    break;
                }

                //cout << atoi(informationFromFile.c_str()) << endl;
                //system("pause");

                informationFromFile = "";
                numberOfInformationFromFile++;
            }
        numberOfInformationFromFile = 1;
        transactions.push_back(transaction);
        }
    }

    //cout << "pierwsza data: " << transactions[0].getDate() << endl;
    //cout << "druga data: " << transactions[1].getDate() << endl;
    //system("pause");

    return transactions;
}

int TransactionsFile::getIdOfLastTransactionFromFile()
{
    int idOfLastTransaction = 0;
    CMarkup xml_transactions;

    bool transactionsFileExists = xml_transactions.Load( "transactions.xml" );
    xml_transactions.FindElem();
    xml_transactions.IntoElem();

    while (xml_transactions.FindElem("Transaction"))
    {
        xml_transactions.FindChildElem("TransactionId");
        idOfLastTransaction = atoi(MCD_2PCSZ(xml_transactions.GetChildData()));
    }

    xml_transactions.Save("transactions.xml");

    return idOfLastTransaction;
}
