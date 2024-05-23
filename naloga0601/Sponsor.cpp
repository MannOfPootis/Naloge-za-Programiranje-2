//
// Created by doominik on 11.4.2024.
//

#include "Sponsor.h"
#include "sstream"

Sponsor::Sponsor(const std::string &name, unsigned int yearsOfSponsorship) : name(name),
                                                                             yearsOfSponsorship(yearsOfSponsorship) {}

std::string Sponsor::toString() {
    std::stringstream ss;
    ss<<"ime sponzorja:"<<getName()<<"  sponzorilral za:"<<yearsOfSponsorship<< " let "<<calculateScore()<<" ";
    return ss.str();
}

std::string Sponsor::getName() const {
    return name;
}

unsigned int Sponsor::getYearsOfSponsorship() const {
    return yearsOfSponsorship;
}

void Sponsor::setName(const std::string &name) {
    Sponsor::name = name;
}

void Sponsor::setYearsOfSponsorship(unsigned int yearsOfSponsorship) {
    Sponsor::yearsOfSponsorship = yearsOfSponsorship;
}
