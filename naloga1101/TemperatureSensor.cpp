#include "TemperatureSensor.h"
#include <sstream>
#include <string>
TemperatureSensor::TemperatureSensor(int id, bool active, TemperatureUnit unit)
    : Sensor(id, active), unit(unit) {}


std::string TemperatureSensor::toString() const {
    std::stringstream ss;
    std::string s;
    if (unit == TemperatureUnit::CELSIUS)
    {
        s = "1";
    }
    else if(unit == TemperatureUnit::FAHRENHEIT)
    {
        s = "2";
    }
    else
    {
        s = "3";
    }
    ss << id << ";" << active << ";" ;
    return ss.str();
}

TemperatureUnit TemperatureSensor::getTemperatureUnit() const {
    return unit;
}
