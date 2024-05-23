//
// Created by doominik on 29.3.2024.
//

#include "Coordinates.h"
#include "sstream"

Coordinates::Coordinates(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

double Coordinates::getLatitude() const {
    return latitude;
}

double Coordinates::getLongitude() const {
    return longitude;
}

void Coordinates::setLatitude(double latitude) {
    Coordinates::latitude = latitude;
}

void Coordinates::setLongitude(double longitude) {
    Coordinates::longitude = longitude;
}

std::string Coordinates::toString() const {
    std::stringstream ss;
    ss << "lat: " << latitude << "\n lon: " << longitude;

    return ss.str();
}

