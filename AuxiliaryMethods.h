#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdio>

using namespace std;

class AuxiliaryMethods
{
public:
    static string getLine();
    static char getChar();
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static int convertAmountStringToInt(string amountAsString);
    static string convertAmountIntToString(int amountAsInt);
    static string changeFirstLetterToCapitalAndOthersToSmallLetters(string text);
};

#endif
