//
// Created by doominik on 4.4.2024.
//

#ifndef NALOGA0502_PERSON_H
#define NALOGA0502_PERSON_H

#include "string"

class Person {
    std::string firstName;
    std::string lastName;
public:
    Person(const std::string &firstName, const std::string &lastName);

    std::string toString() const;
};


#endif //NALOGA0502_PERSON_H
