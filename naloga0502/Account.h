//
// Created by doominik on 4.4.2024.
//

#ifndef NALOGA0502_ACCOUNT_H
#define NALOGA0502_ACCOUNT_H


#include <cstdlib>
#include "Person.h"

class Account {
protected:
    Person *owner;
    uint number;
    double balance;

public:

    Account(Person *owner, uint number, double balance);



    bool makeDeposit(double val);

    virtual bool makeWithdrawl(double val);

    virtual ~Account();

    virtual std::string toString() const;

    Person *getOwner() const;

    uint getNumber() const;

    double getBalance() const;
};


#endif //NALOGA0502_ACCOUNT_H
