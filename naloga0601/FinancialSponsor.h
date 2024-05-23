//
// Created by doominik on 11.4.2024.
//

#ifndef NALOGA0401_FINANCIALSPONSOR_H
#define NALOGA0401_FINANCIALSPONSOR_H

#include "Sponsor.h"
class FinancialSponsor: public Sponsor {
    float moneyDonated;
    float bankAccount;
public:
    FinancialSponsor(const std::string &name, unsigned int yearsOfSponsorship, float moneyDonated, float bankAccount);
    std::string toString() override;
    const float calculateScore() override;
};


#endif //NALOGA0401_FINANCIALSPONSOR_H
