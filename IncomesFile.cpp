#include "IncomesFile.h"
#include "Markup.h"

bool IncomesFile::addIncomeToFile(Income income)
{
    CMarkup xml_incomes;

    bool incomesFileExists = xml_incomes.Load( "incomes.xml" );

    if (!incomesFileExists)
    {
        xml_incomes.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml_incomes.AddElem("Incomes");
    }

    xml_incomes.FindElem();
    xml_incomes.IntoElem();
    xml_incomes.AddElem("Income");
    xml_incomes.IntoElem();
    xml_incomes.AddElem("IncomeId", income.getIncomeId());
    xml_incomes.AddElem("UserId", income.getUserId());
    xml_incomes.AddElem("Date", AuxiliaryMethods::convertDateFromIntToString(income.getDate()));
    xml_incomes.AddElem("Item", income.getItem());
    xml_incomes.AddElem("Amount", income.getAmount());

    xml_incomes.Save("incomes.xml");

    return true;    //do poprawy, moze uwzglednic spr czy plik good
}

vector<Income> IncomesFile::getIncomesOfLoggedInUserFromFile(int idOfLoggedUser)
{
    Income income;
    vector<Income> incomes;
    string informationFromFile = "";
    int numberOfInformationFromFile = 1;

    CMarkup xml_incomes;;

    bool incomesFileExists = xml_incomes.Load( "incomes.xml" );
    xml_incomes.FindElem();
    xml_incomes.IntoElem();

    while (xml_incomes.FindElem("Income"))
    {
        xml_incomes.FindChildElem("UserId");

        if (atoi(MCD_2PCSZ(xml_incomes.GetChildData())) == idOfLoggedUser)
        {
            xml_incomes.ResetChildPos(); //child byl na user id, a chce od poczatku - od transaction id

            while (xml_incomes.FindChildElem())
            {
                informationFromFile = xml_incomes.GetChildData();

                switch(numberOfInformationFromFile)
                {
                case 1:
                    income.setIncomeId(atoi(informationFromFile.c_str()));
                    break;
                case 2:
                    income.setUserId(atoi(informationFromFile.c_str()));
                    break;
                case 3:
                    income.setDate(informationFromFile);
                    //bo w pliku siedzi jako string; teraz setDate dostanie stringa - jak przy inpucie
                    break;
                case 4:
                    income.setItem(informationFromFile);
                    break;
                case 5:
                    income.setAmount(informationFromFile);
                    //bo w pliku siedzi jako string; teraz setAmount dostanie stringa - jak przy inpucie
                    break;
                }

                informationFromFile = "";
                numberOfInformationFromFile++;
            }
        numberOfInformationFromFile = 1;
        incomes.push_back(income);
        }
    }

    return incomes;
}

int IncomesFile::getIdOfLastTransactionFromFile()
{
    int idOfLastTransaction = 0;
    CMarkup xml_incomes;

    bool incomesFileExists = xml_incomes.Load( "incomes.xml" );
    xml_incomes.FindElem();
    xml_incomes.IntoElem();

    while (xml_incomes.FindElem("Income"))
    {
        xml_incomes.FindChildElem("IncomeId");
        idOfLastTransaction = atoi(MCD_2PCSZ(xml_incomes.GetChildData()));
    }

    xml_incomes.Save("incomes.xml");

    return idOfLastTransaction;
}
