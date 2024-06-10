#pragma once

#include "TemperatureSensor.h"

class TemperatureSensorGPS final : public TemperatureSensor {
private:
    float latitude;
    float longitude;

public:
    TemperatureSensorGPS(int id, bool active, TemperatureUnit unit, float latitude, float longitude);

    std::string toString() const override;

    float getLatitude() const;
    float getLongitude() const;
};
