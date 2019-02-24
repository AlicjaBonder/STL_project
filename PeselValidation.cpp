#include "PeselValidation.hpp"
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

bool isMonthValid(int month)
{
    const std::array<int, 24> lookupTable = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                                             21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
    return std::find(lookupTable.begin(), lookupTable.end(), month) != lookupTable.end();
}

bool isLeapYear(int year)
{
    return ((not(year % 4)) and (year % 100)) or (not(year % 400));
}

bool isDayValid(int day, int maxDay)
{
    return day >= 1 and day <= maxDay;
}

int calculateMaxDay(int year, int month)
{
    const std::array<int, 4> monthsWith30Days = {4, 6, 9, 11};
    if (std::find(monthsWith30Days.begin(), monthsWith30Days.end(), month) != monthsWith30Days.end())
    {
        return 30;
    }
    else if (month == 2 and isLeapYear(year))
    {
        return 29;
    }
    else if (month == 2 and not isLeapYear(year))
    {
        return 28;
    }
    return 31;
}

bool isDateValid(int year, int month, int day)
{
    if (not isMonthValid(month))
    {
        return false;
    }
    month > 20 ? month -= 20 : month;
    int maxDay = calculateMaxDay(year, month);
    return isDayValid(day, maxDay);
}

bool isGenderValid(int number, Gender gender)
{
    return (gender == Gender::Male and number % 2) or
           (gender == Gender::Female and not number % 2);
}

bool isChecksumValid(const std::string &pesel)
{
    std::vector<int> numericPesel;
    std::transform(pesel.begin(), pesel.end(), back_inserter(numericPesel), [](auto c) { return c - '0'; });

    const std::array<int, 11> factors = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int result = std::inner_product(numericPesel.begin(), numericPesel.end(), factors.begin(), 0);
    return not(result % 10);
}

bool isPeselValid(const std::string &pesel, Gender gender)
{
    bool isValid = std::all_of(pesel.begin(), pesel.end(), [](auto c) { return std::isdigit(c); });
    int year = std::stoi(pesel.substr(0, 2));
    int month = std::stoi(pesel.substr(2, 2));
    int day = std::stoi(pesel.substr(4, 2));
    isValid &= isDateValid(year, month, day);
    isValid &= isGenderValid(std::stoi(pesel.substr(9, 1)), gender);
    isValid &= isChecksumValid(pesel);
    return isValid;
}
