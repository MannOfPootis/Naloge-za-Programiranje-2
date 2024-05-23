//
// Created by doominik on 5.4.2024.
//

#include "Transaction.h"
#include "sstream"

Transaction::Transaction(unsigned int accountNumber, const Date &date, double ammount) : accountNumber(accountNumber),
                                                                                         date(date), ammount(ammount) {}

unsigned int Transaction::getAccountNumber() const {
    return accountNumber;
}

const Date &Transaction::getDate() const {
    return date;
}

double Transaction::getAmmount() const {
    return ammount;
}

void Transaction::setAccountNumber(unsigned int accountNumber) {
    Transaction::accountNumber = accountNumber;
}

void Transaction::setDate(const Date &date) {
    Transaction::date = date;
}

void Transaction::setAmmount(double ammount) {
    Transaction::ammount = ammount;
}

Transaction::~Transaction() {

}

std::string Transaction::toString() {
    std::stringstream ss;
    ss<<"račun: "<<accountNumber<< " je na datum: "<<date.toString()<<" spremenil svoje stanje za: "<<ammount;
    return ss.str();
}
