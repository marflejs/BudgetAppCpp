#include "DateManager.h"
#include "AuxiliaryMethods.h"

bool DateManager::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int DateManager::calculateNumberOfDaysInMonth(int month, int year)
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

int DateManager::convertDateStringToInt(string dateStringInput)
{
    dateStringInput.erase(4, 1);
    dateStringInput.erase(6, 1);
    return AuxiliaryMethods::convertStringToInt(dateStringInput);
}

string DateManager::convertDateFromIntToString(int dateAsInt)
{
    string dateAsString = AuxiliaryMethods::convertIntToString(dateAsInt);
    dateAsString.insert(4, "-");
    dateAsString.insert(7, "-");
    return dateAsString;
}

string DateManager::getCurrentDate()
{
    time_t rawtime;
    tm* timeinfo;
    char currentDate [80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(currentDate,80,"%Y-%m-%d",timeinfo);

    return currentDate;
}

bool DateManager::isDateOk(string newDate)
{
    bool isDateOk = true;
    int newYear, newMonth, newDay;
    sscanf(newDate.c_str(), "%4d-%2d-%2d", &newYear, &newMonth, &newDay);

    if(newYear < 2000 ||
        newMonth <= 0 ||
        newMonth > 12 ||
        newDay <= 0 ||
        newDay > calculateNumberOfDaysInMonth(newMonth, newYear))
        {
            cout << "Niepoprawna data. Wprowadz ponownie" << endl;
            isDateOk = false;
        }
    return isDateOk;
}
