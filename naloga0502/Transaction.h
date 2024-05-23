//
// Created by doominik on 5.4.2024.
//

#ifndef NALOGA0502_TRANSACTION_H
#define NALOGA0502_TRANSACTION_H
#include "Date.h"

class Transaction {
    unsigned int accountNumber;
    Date date;
    double ammount;

public:
    Transaction(unsigned int accountNumber, const Date &date, double ammount);

    virtual ~Transaction();

    unsigned int getAccountNumber() const;

    const Date &getDate() const;

    double getAmmount() const;

    void setAccountNumber(unsigned int accountNumber);

    void setDate(const Date &date);

    void setAmmount(double ammount);
    std::string toString();
};


#endif //NALOGA0502_TRANSACTION_H
