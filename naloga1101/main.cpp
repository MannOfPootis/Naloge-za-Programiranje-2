#include "SensorHub.h"
#include "TemperatureSensor.h"
#include "TemperatureSensorGPS.h"
#include "DuplicatedSensorIdException.h"
#include "InvalidLocationException.h"

#include <iostream>
#include <valarray>

int main() {
    SensorHub sensorHub;

    try {
        TemperatureSensor(1, true, TemperatureUnit::FAHRENHEIT);
        sensorHub.addSensor(std::make_unique<TemperatureSensor>(1, true, TemperatureUnit::CELSIUS));
        try {
            sensorHub.addSensor(
                    std::make_unique<TemperatureSensorGPS>(2, true, TemperatureUnit::FAHRENHEIT, 12.56, -34.567));
        }
        catch (const InvalidLocationException &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        sensorHub.addSensor(std::make_unique<TemperatureSensor>(3, true, TemperatureUnit::KELVIN));
        sensorHub.addSensor(std::make_unique<TemperatureSensor>(4, true, TemperatureUnit::CELSIUS));
        try {
            sensorHub.addSensor(
                    std::make_unique<TemperatureSensorGPS>(5, true, TemperatureUnit::KELVIN, sqrt(2), -122.4194));
        }
        catch (const InvalidLocationException &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "Reading sensor values:\n";
        sensorHub.readValues();
        sensorHub.writeSensorsToFile("sensors.txt");
        SensorHub sensorHubFromFile;
        sensorHubFromFile.readSensorsFromFile("sensors.txt");
        std::cout << "\nReading sensor values from file:\n";
        sensorHubFromFile.readValues();
    }
    catch (const DuplicatedSensorIdException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const InvalidLocationException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
