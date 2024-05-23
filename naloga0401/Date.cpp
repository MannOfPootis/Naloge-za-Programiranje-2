//
// Created by doominik on 26.3.2024.
//

#include "Date.h"

#include <vector>
#include <string>
#include <ctime>
#include <sstream>

const std::vector<unsigned int> Date::MaxDayByMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const unsigned int Date::MaxMonth = 12;
const unsigned int Date::DaysInYear = 365;

Date::Date(unsigned int d, unsigned int m, unsigned int y) {
    if (isDateValid(d, m, y)) {
        day = d;
        month = m;
        year = y;
    } else {
        day = 1;
        month = 1;
        year = 1970;
    }
}
Date Date::getTodysDate() {
    // current date/time based on current system
    time_t now = time(0);

    tm *ltm = localtime(&now);


    return Date(ltm->tm_mday,ltm->tm_mon,1900+ltm->tm_year);
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << day << ". " << month << ". " << year;
    return ss.str();
}

bool Date::isLeapYear(unsigned int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned int Date::getDaysInMonth(unsigned int month, unsigned int year) {
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return MaxDayByMonth[month - 1];
}

bool Date::isDateValid(unsigned int d, unsigned int m, unsigned int y) {
    if (m < 1 || m > MaxMonth || d < 1 || d > getDaysInMonth(m, y))
        return false;
    return true;
}


