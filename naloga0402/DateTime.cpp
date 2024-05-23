//
// Created by doominik on 28.3.2024.
//

#include "DateTime.h"

DateTime::DateTime(const Date &date, const Time &time) : date(date), time(time) {
}

const Date &DateTime::getDate() const {
    return date;
}

const Time &DateTime::getTime() const {
    return time;
}

const unsigned long DateTime::toSeconds() const {//future proof
    return time.toSeconds()+
    date.getDaysSinceEpoch()*24*3600;
}

DateTime DateTime::getCurrentTime() {
    return DateTime(Date::getTodysDate(),Time::getCurrentTime()) ;
}

std::string DateTime::toString() const{

    return time.toString()+" "+date.toString();
}
