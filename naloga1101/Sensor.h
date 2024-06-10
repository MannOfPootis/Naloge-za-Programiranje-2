#pragma once

#include <string>

class Sensor {
protected:
    int id;
    bool active;

public:
    Sensor(int id, bool active);
    int getId() const;
    bool isActive() const;
    virtual std::string toString() const;
    float readValue();
};
