//
// Created by doominik on 4.4.2024.
//

#include "Person.h"

Person::Person(const std::string &firstName, const std::string &lastName) : firstName(firstName), lastName(lastName) {}

std::string Person::toString() const {

    return firstName+ " "+ lastName;
}
