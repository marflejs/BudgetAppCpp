#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>

using namespace std;

class DateManager
{
    static bool isLeapYear(int year);
    static int calculateNumberOfDaysInMonth(int month, int year);
public:

    static string getCurrentDate();
    static bool isDateOk(string newDate);
    static int convertDateStringToInt(string number);
    static string convertDateFromIntToString(int dateAsInt);

};

#endif
