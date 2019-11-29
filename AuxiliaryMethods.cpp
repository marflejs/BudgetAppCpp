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

int AuxiliaryMethods::convertDateStringToInt(string number)
{
    cout << "przekonwertowano" << endl;
    return 1;
}

float AuxiliaryMethods::convertStringToFloat(string amount)
{
    return 1.0;
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

string AuxiliaryMethods::changeCommaToDot(string text)
{
    cout << "zmieniono przecinek na kropke" << endl;
    return ".";
}
