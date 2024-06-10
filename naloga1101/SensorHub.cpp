#include "SensorHub.h"
#include "InvalidLocationException.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

// Constructor
SensorHub::SensorHub() {}

// Destructor
//TODO
SensorHub::~SensorHub() {}

// Method to add sensor
void SensorHub::addSensor(std::unique_ptr<Sensor> sensor) {
    for (const auto &s: sensors) {
        if (s->getId() == sensor->getId()) {
            throw DuplicatedSensorIdException(sensor->getId());
        }
    }
    sensors.push_back(std::move(sensor));
}

void SensorHub::readValues() const {
    for (const auto &sensor: sensors) {
        if (sensor->isActive()) {
            std::cout << sensor->toString() << ", Value: " << sensor->readValue() << std::endl;
        }
    }
}

void SensorHub::writeSensorsToFile(const std::string &filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    for (const auto &sensor: sensors) {
        file << sensor->toString() << "\n";
    }

    file.close();
}

void SensorHub::readSensorsFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    try {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> tokens;
            while (std::getline(iss, token, ';')) {
                tokens.push_back(token);
            }

            int id = std::stoi(tokens[0]);
            bool active = std::stoi(tokens[1]);
            if (tokens.size() == 4) {
                TemperatureUnit unit = static_cast<TemperatureUnit>(std::stoi(tokens[3]));
                try {
                    addSensor(std::make_unique<TemperatureSensor>(id, active, unit));
                }
                catch (const DuplicatedSensorIdException &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;

                }
            } else if (tokens.size() == 6) {
                TemperatureUnit unit = static_cast<TemperatureUnit>(std::stoi(tokens[3]));
                float latitude = std::stof(tokens[4]);
                float longitude = std::stof(tokens[5]);
                try {
                    addSensor(std::make_unique<TemperatureSensorGPS>(id, active, unit, latitude, longitude));
                } catch (const InvalidLocationException &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
                catch (const DuplicatedSensorIdException &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                } catch (const std::invalid_argument &e) {
                    std::cerr << "Error: " << e.what() << std::endl;

                }
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error while reading sensors from file: " << e.what() << std::endl;
    }

    file.close();
}