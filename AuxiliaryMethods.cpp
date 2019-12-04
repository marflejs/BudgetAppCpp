#include "AuxiliaryMethods.h"

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

string AuxiliaryMethods::changeFirstLetterToCapitalAndOthersToSmallLetters(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
