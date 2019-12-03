#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

bool AuxiliaryMethods::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int AuxiliaryMethods::calculateNumberOfDaysInMonth(int month, int year)
{
    int numberOfDays;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        numberOfDays = 30;
    else if (month == 2)
    {
        if (isLeapYear(year))
            numberOfDays = 29;
        else
            numberOfDays = 28;
    }
    else
        numberOfDays = 31;

    return numberOfDays;
}

int AuxiliaryMethods::convertDateStringToInt(string dateStringInput)
{
    dateStringInput.erase(4, 1);
    dateStringInput.erase(6, 1);
    return convertStringToInt(dateStringInput);
}

string AuxiliaryMethods::convertDateFromIntToString(int dateAsInt)
{
    string dateAsString = convertIntToString(dateAsInt);
    dateAsString.insert(4, "-");
    dateAsString.insert(7, "-");
    return dateAsString;
}

int AuxiliaryMethods::convertAmountStringToInt(string amountAsString)
{
    if(amountAsString.find(',') != string::npos || amountAsString.find('.') != string::npos)
    {
        for(int i = 0; i < amountAsString.length(); i++)
        {
            if(amountAsString[i] == '.' || amountAsString[i] == ',')
            {
                amountAsString.erase(i, 1);
                break;
            }
        }
    }
    else
        amountAsString += "00";

    int amountAsInt = atoi(amountAsString.c_str());

    return amountAsInt;
}

string AuxiliaryMethods::convertAmountIntToString(int amountAsInt)
{
    string amountAsString = convertIntToString(amountAsInt);
    amountAsString.insert(amountAsString.length() - 2, ".");
    return amountAsString;

}

string AuxiliaryMethods::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::getChar()
{
    string input = "";
    char character = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::getInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest number. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

string AuxiliaryMethods::getCurrentDate()
{
    time_t rawtime;
    tm* timeinfo;
    char currentDate [80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(currentDate,80,"%Y-%m-%d",timeinfo);

    return currentDate;
}

bool AuxiliaryMethods::isDateOk(string newDate)
{
    bool isDateOk = true;
    int newYear, newMonth, newDay;
    sscanf(newDate.c_str(), "%4d-%2d-%2d", &newYear, &newMonth, &newDay);

    if(newYear < 2000 ||
        newMonth <= 0 ||
        newMonth > 12 ||
        newDay <= 0 ||
        newDay > AuxiliaryMethods::calculateNumberOfDaysInMonth(newMonth, newYear))
        {
            cout << "Niepoprawna data. Wprowadz ponownie" << endl;
            isDateOk = false;
        }

    return isDateOk;
}




