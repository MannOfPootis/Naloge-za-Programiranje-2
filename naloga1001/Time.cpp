//
// Created by doominik on 27.3.2024.
//

#include <chrono>
#include "Time.h"
#include "sstream"
//uint Time::timeStandard={60,60,24};

Time::Time(uint hours, uint minutes, uint seconds) : hours(hours%timeStandard[1]+(minutes%timeStandard[1]+seconds/timeStandard[0])/timeStandard[1]),
                                                     minutes(minutes%timeStandard[1]+seconds/timeStandard[0]),
                                                     seconds(seconds%timeStandard[0]) {}

std::string Time::toString() const {
    std::stringstream ss;
    ss<<hours<<":"<<minutes<<":"<<seconds;
    return ss.str();
}


bool Time::isTimeValid(uint hours, uint minutes, uint seconds) {
    return seconds< timeStandard[0]&&minutes<timeStandard[1]&&hours<timeStandard[2];
}

uint Time::toSeconds() const {
    return hours*3600+minutes*60+seconds;
}

Time Time::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm *ltm = std::localtime(&now_c);
    return Time(ltm->tm_hour, ltm->tm_min, ltm->tm_sec);}
