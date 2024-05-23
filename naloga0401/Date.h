//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_DATE_H
#define NALOGA0401_DATE_H


#include <vector>
#include <string>
#include <sstream>      // std::stringstream
class Date {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

    static const std::vector<unsigned int> MaxDayByMonth;
    static const unsigned int MaxMonth;
    static const unsigned int DaysInYear;

public:
    Date(unsigned int d, unsigned int m, unsigned int y);
    std::string toString() const;
    static bool isLeapYear(unsigned int year);
    static unsigned int getDaysInMonth(unsigned int month, unsigned int year);
    static bool isDateValid(unsigned int day, unsigned int month, unsigned int year);
    static Date getTodysDate();
};



#endif //NALOGA0401_DATE_H
