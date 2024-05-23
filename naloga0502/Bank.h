//
// Created by doominik on 4.4.2024.
//

#ifndef NALOGA0502_BANK_H
#define NALOGA0502_BANK_H

#include "vector"
#include "Account.h"
#include "SavingsAccount.h"
#include "Transaction.h"
class Bank {

    std::vector<Account*> accounts;
    std::vector<Transaction> transactions;
public:
    virtual ~Bank();

    explicit Bank();
    void addAccount(Account account);
    std::vector<Account*> getAccounts(Person *person);
    bool makeDepositOnAccount(double amount ,uint number);
    bool makeWithdrawlOnAccount(double amount ,uint number);
    void applyIneterest();



    std::string toString();

    void getTransactionsByAccount(unsigned int accountNumber);
    void addAccount(Account *account);
};


#endif //NALOGA0502_BANK_H
