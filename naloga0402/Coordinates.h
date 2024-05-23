//
// Created by doominik on 29.3.2024.
//

#ifndef NALOGA0401_COORDINATES_H
#define NALOGA0401_COORDINATES_H
#include "string"

class Coordinates {
    double latitude;
    double longitude;
public:
    std::string  toString() const;

    Coordinates(double latitude, double longitude);

    void setLatitude(double latitude);

    void setLongitude(double longitude);

    double getLatitude() const;

    double getLongitude() const;


};


#endif //NALOGA0401_COORDINATES_H
