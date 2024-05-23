//
// Created by doominik on 4.4.2024.
//

#include "Account.h"
#include "iostream"
#include "sstream"
Account::Account(Person *owner, uint number, double balance) : owner(owner), number(number), balance(balance) {}

Account::~Account() {
std::cout<<balance<<" EUR was deleted\n";
}

bool Account::makeDeposit(double val) {
    if(val<0)
        return false;
    balance+=val;
}

bool Account::makeWithdrawl(double val) {
    if(val<0)
        return false;
    balance-=val;
}

std::string Account::toString() const {
    std::stringstream ss;
    ss<<owner->toString() <<" ima na računu: "<<balance<< " EUR\n";

    return ss.str();
}

Person *Account::getOwner() const {
    return owner;
}

uint Account::getNumber() const {
    return number;
}

double Account::getBalance() const {
    return balance;
}

