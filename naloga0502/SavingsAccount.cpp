//
// Created by doominik on 4.4.2024.
//

#include <sstream>
#include "SavingsAccount.h"
#include "iostream";

SavingsAccount::SavingsAccount(Person *owner, uint number, double balance, double intrestRate) : Account(owner, number,
                                                                                                         balance),
                                                                                                 intrestRate(
                                                                                                         intrestRate),
                                                                                                 withdrawlDate(Date(1,1,1970)) {}

bool SavingsAccount::makeWithdrawl(double val) {

    if(val<0||((Date::getTodysDate().getDaysSinceEpoch()-this->withdrawlDate.getDaysSinceEpoch())<90))
        return false;
    balance-=val;
    withdrawlDate=Date::getTodysDate();
    return true;
}

std::string SavingsAccount::toString() const {
    std::stringstream ss;
    ss<<Account::toString()+" obrestna mera: "<<100*intrestRate<<"%";
    return ss.str();
}

double SavingsAccount::getIntrestRate() const {
    return intrestRate;
}
