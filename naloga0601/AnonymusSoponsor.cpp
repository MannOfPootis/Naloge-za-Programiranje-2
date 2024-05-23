//
// Created by doominik on 12.4.2024.
//

#include "AnonymusSoponsor.h"

AnonymusSoponsor::AnonymusSoponsor(const std::string &name, unsigned int yearsOfSponsorship, float moneyDonated,
                                   float bankAccount) : FinancialSponsor(name, yearsOfSponsorship, moneyDonated,
                                                                         bankAccount) {}


std::string AnonymusSoponsor::getName() const {
    return "Anonymus";
}

const float AnonymusSoponsor::calculateScore() {
    return FinancialSponsor::calculateScore() * 2;
}
