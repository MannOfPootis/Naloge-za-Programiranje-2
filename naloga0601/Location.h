//
// Created by doominik on 26.3.2024.
//

#ifndef NALOGA0401_LOCATION_H
#define NALOGA0401_LOCATION_H

#include <string>
#include "Coordinates.h"
class Location {
private:
    std::string name;
    std::string street;
    std::string city;
    std::string country;
    Coordinates coordinates;
public:
    const Coordinates &getCoordinates() const;

    void setCoordinates(const Coordinates &coordinates);

    Location(const std::string &name, const std::string &street, const std::string &city, const std::string &country);

    Location(const std::string &name, const std::string &street, const std::string &city, const std::string &country,
             const Coordinates &coordinates);

    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getStreet() const;
    void setStreet(const std::string &street);

    const std::string &getCity() const;
    void setCity(const std::string &city);

    const std::string &getCountry() const;
    void setCountry(const std::string &country);

    std::string toString() const;
};


#endif //NALOGA0401_LOCATION_H
