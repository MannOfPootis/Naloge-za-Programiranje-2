#pragma once

#include "Sensor.h"

enum class TemperatureUnit {
    CELSIUS,
    FAHRENHEIT,
    KELVIN
};

class TemperatureSensor : public Sensor {
protected:
    TemperatureUnit unit;

public:
    TemperatureSensor(int id, bool active, TemperatureUnit unit = TemperatureUnit::CELSIUS);

    std::string toString() const override;

    TemperatureUnit getTemperatureUnit() const;
};
