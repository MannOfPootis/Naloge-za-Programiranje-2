//
// Created by doominik on 11.4.2024.
//

#ifndef NALOGA0401_SPONSOR_H
#define NALOGA0401_SPONSOR_H

#include <string>

class Sponsor {
protected:
    std::string name;
    unsigned int yearsOfSponsorship;

public:
    Sponsor(const std::string &name, unsigned int yearsOfSponsorship);

    virtual const float calculateScore() = 0;

    virtual std::string toString();

    virtual std::string getName() const;

    virtual unsigned int getYearsOfSponsorship() const;

    void setName(const std::string &name);

    void setYearsOfSponsorship(unsigned int yearsOfSponsorship);

};


#endif //NALOGA0401_SPONSOR_H
