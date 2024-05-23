//
// Created by doominik on 11.4.2024.
//

#include <sstream>
#include "FinancialSponsor.h"

FinancialSponsor::FinancialSponsor(const std::string &name, unsigned int yearsOfSponsorship, float moneyDonated,
                                   float bankAccount) : Sponsor(name, yearsOfSponsorship), moneyDonated(moneyDonated),
                                                        bankAccount(bankAccount) {}

std::string FinancialSponsor::toString() {
    std::stringstream ss;
    ss<<Sponsor::toString()<<" "<< moneyDonated<<"$ "<<bankAccount;
    return ss.str();
}

const float FinancialSponsor::calculateScore() {
    return (0.7f*moneyDonated)+(0.3f*yearsOfSponsorship)/(moneyDonated+yearsOfSponsorship);
}
