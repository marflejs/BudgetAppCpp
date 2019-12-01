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
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static int convertDateStringToInt(string number);
    static int convertAmountStringToInt(string amountAsString);
    static string getLine();
    static char getChar();
    static string changeFirstLetterToCapitalAndOthersToSmallLetters(string text);
    static int getInteger();
    static string getNumber(string tekst, int charPosition);
    static string changeCommaToDot(string text);
    static bool isLeapYear(int year);
    static int calculateNumberOfDaysInMonth(int month, int year);
    static string convertDateFromIntToString(int dateAsInt);
    static string getCurrentDate();
};

#endif
