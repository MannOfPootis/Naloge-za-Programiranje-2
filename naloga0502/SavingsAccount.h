//
// Created by doominik on 4.4.2024.
//

#ifndef NALOGA0502_SAVINGSACCOUNT_H
#define NALOGA0502_SAVINGSACCOUNT_H
#include "Account.h"
#include "Date.h"
class SavingsAccount :public Account{
double intrestRate;
Date withdrawlDate ;
public:

    SavingsAccount(Person *owner, uint number, double balance, double intrestRate);
    bool makeWithdrawl(double val) override;
    std::string toString()const override;

    double getIntrestRate() const;
};


#endif //NALOGA0502_SAVINGSACCOUNT_H
