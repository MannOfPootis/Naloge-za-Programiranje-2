#include "Sensor.h"
#include <sstream>
#include <cstdlib> 
#include <ctime>
Sensor::Sensor(int id, bool active) : id(id), active(active){}

int Sensor::getId() const {
    return id;
}

bool Sensor::isActive() const {
    return active;
}

std::string Sensor::toString() const {
    std::stringstream ss;
    ss << id << ";" << active << ";" ;
    return ss.str();
}

float Sensor::readValue() {
    return rand()%100;
}

