#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Sensor.h"
#include "TemperatureSensor.h"
#include "TemperatureSensorGPS.h"
#include "DuplicatedSensorIdException.h"

class SensorHub {
private:
    std::vector<std::unique_ptr<Sensor>> sensors;

public:
    SensorHub();
    ~SensorHub();

    void addSensor(std::unique_ptr<Sensor> sensor);
    void readValues() const;
    void writeSensorsToFile(const std::string& filename) const;
    void readSensorsFromFile(const std::string& filename);
};
