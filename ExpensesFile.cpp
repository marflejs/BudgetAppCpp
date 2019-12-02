#include "ExpensesFile.h"
#include "Markup.h"

bool ExpensesFile::addExpenseToFile(Expense expense)
{
    CMarkup xml_expenses;

    bool expensesFileExists = xml_expenses.Load( "expenses.xml" );

    if (!expensesFileExists)
    {
        xml_expenses.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_expenses.AddElem("Expenses");
    }

    xml_expenses.FindElem();
    xml_expenses.IntoElem();
    xml_expenses.AddElem("Expense");
    xml_expenses.IntoElem();
    xml_expenses.AddElem("ExpenseId", expense.getExpenseId());
    xml_expenses.AddElem("UserId", expense.getUserId());
    xml_expenses.AddElem("Date", AuxiliaryMethods::convertDateFromIntToString(expense.getDate()));
    xml_expenses.AddElem("Item", expense.getItem());
    xml_expenses.AddElem("Amount", AuxiliaryMethods::convertAmountIntToString(expense.getAmount()));

    xml_expenses.Save("expenses.xml");

    return true;    //do poprawy, uwzglednic spr czy plik good
}

vector<Expense> ExpensesFile::getExpensesOfLoggedInUserFromFile(int idOfLoggedUser)
{
    Expense expense;
    vector<Expense> expenses;
    string informationFromFile = "";
    int numberOfInformationFromFile = 1;

    CMarkup xml_expenses;;

    bool expensesFileExists = xml_expenses.Load( "expenses.xml" );
    xml_expenses.FindElem();
    xml_expenses.IntoElem();

    while (xml_expenses.FindElem("Expense"))
    {
        xml_expenses.FindChildElem("UserId");

        if (atoi(MCD_2PCSZ(xml_expenses.GetChildData())) == idOfLoggedUser)
        {
            xml_expenses.ResetChildPos(); //child byl na user id, a chce od poczatku - od transaction id

            while (xml_expenses.FindChildElem())
            {
                informationFromFile = xml_expenses.GetChildData();

                switch(numberOfInformationFromFile)
                {
                case 1:
                    expense.setExpenseId(atoi(informationFromFile.c_str()));
                    break;
                case 2:
                    expense.setUserId(atoi(informationFromFile.c_str()));
                    break;
                case 3:
                    expense.setDate(informationFromFile);
                    //bo w pliku siedzi jako string; teraz setDate dostanie stringa - jak przy inpucie
                    break;
                case 4:
                    expense.setItem(informationFromFile);
                    break;
                case 5:
                    expense.setAmount(informationFromFile);
                    //bo w pliku siedzi jako string; teraz setAmount dostanie stringa - jak przy inpucie
                    break;
                }
                informationFromFile = "";
                numberOfInformationFromFile++;
            }
        numberOfInformationFromFile = 1;
        expenses.push_back(expense);
        }
    }

    return expenses;
}

int ExpensesFile::getIdOfLastTransactionFromFile()
{
    int idOfLastTransaction = 0;
    CMarkup xml_expenses;

    bool expensesFileExists = xml_expenses.Load( "expenses.xml" );
    xml_expenses.FindElem();
    xml_expenses.IntoElem();

    while (xml_expenses.FindElem("Expense"))
    {
        xml_expenses.FindChildElem("ExpenseId");
        idOfLastTransaction = atoi(MCD_2PCSZ(xml_expenses.GetChildData()));
    }

    xml_expenses.Save("expenses.xml");

    return idOfLastTransaction;
}
