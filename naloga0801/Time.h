#ifndef TASK0302_TIME_H
#define TASK0302_TIME_H

#include <iostream>

class Time {
private:
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

public:
    Time();
    Time(unsigned int hours, unsigned int minutes, unsigned int seconds);
    Time(const Time &time);

    unsigned int getHours() const;
    void setHours(unsigned int hours);
    unsigned int getMinutes() const;
    void setMinutes(unsigned int minutes);
    unsigned int getSeconds() const;
    void setSeconds(unsigned int seconds);

    unsigned int toSeconds() const;

    std::string toString() const;
    bool greater(Time t) const{
        if(hours>t.hours)
            return true;
        if(minutes>t.minutes)
            return true;
        if(seconds>t.seconds)
            return true;
        return false;
    }
};


#endif //TASK0302_TIME_H
