//
// Created by doominik on 28.3.2024.
//

#ifndef NALOGA0401_TIME_H
#define NALOGA0401_TIME_H


#include <cstdlib>
#include "string"
class Time {
    uint hours;
    uint minutes;
    uint seconds;
public:
    Time(uint hours, uint minutes, uint seconds);
    constexpr static const uint timeStandard[3]={60,60,24};
    std::string toString() const;
    bool isTimeValid(uint hours, uint minutes, uint seconds);
    uint toSeconds() const ;

    static Time getCurrentTime();
};

#endif //NALOGA0401_TIME_H
