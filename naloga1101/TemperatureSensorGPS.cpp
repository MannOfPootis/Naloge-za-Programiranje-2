#include "TemperatureSensorGPS.h"
#include <sstream>
#include "InvalidLocationException.h"



// Constructor
TemperatureSensorGPS::TemperatureSensorGPS(int id, bool active, TemperatureUnit unit, float latitude, float longitude)
    : TemperatureSensor(id, active, unit), latitude(latitude), longitude(longitude) {
    if(abs(latitude)>90||abs(longitude)>180){
        throw InvalidLocationException();
    }
}

// Method override
std::string TemperatureSensorGPS::toString() const {
    std::stringstream ss;
    std::string s;
    if (unit == TemperatureUnit::CELSIUS)
    {
        s = "1";
    }
    else if (unit == TemperatureUnit::FAHRENHEIT)
    {
        s = "2";
    }
    else
    {
        s = "3";
    }
    ss << id << ";" << active << ";" << ";" << s << ";" << latitude << ";" << longitude ;
    return ss.str();
}

// Getters
float TemperatureSensorGPS::getLatitude() const {
    return latitude;
}

float TemperatureSensorGPS::getLongitude() const {
    return longitude;
}