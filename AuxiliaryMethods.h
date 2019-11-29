#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static int convertDateStringToInt(string number);
    static float convertStringToFloat(string amount);
    static string getLine();
    static char getChar();
    static string changeFirstLetterToCapitalAndOthersToSmallLetters(string text);
    static int getInteger();
    static string getNumber(string tekst, int charPosition);
    static string changeCommaToDot(string text);
};

#endif
