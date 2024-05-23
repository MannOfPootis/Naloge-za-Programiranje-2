//
// Created by doominik on 28.3.2024.
//

#ifndef NALOGA0401_DATETIME_H
#define NALOGA0401_DATETIME_H


#include "Date.h"
#include "Time.h"
class DateTime {
    Date date;
    Time time;
public:
    const Date &getDate() const;

    const Time &getTime() const;
    const unsigned long toSeconds() const;
    std::string toString() const;
    DateTime(const Date &date, const Time &time);

    static DateTime getCurrentTime();
};


#endif //NALOGA0401_DATETIME_H
