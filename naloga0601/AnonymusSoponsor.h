//
// Created by doominik on 12.4.2024.
//

#ifndef NALOGA0401_ANONYMUSSOPONSOR_H
#define NALOGA0401_ANONYMUSSOPONSOR_H
#include "FinancialSponsor.h"

class AnonymusSoponsor: public FinancialSponsor{
public:///tak resno ne vem zakaj ne ustvarimo sam navadnega sponsorja z imenom anonymus sam ok
    AnonymusSoponsor(const std::string &name, unsigned int yearsOfSponsorship, float moneyDonated, float bankAccount);
    std::string getName() const override;

    const float calculateScore() override;

};


#endif //NALOGA0401_ANONYMUSSOPONSOR_H
