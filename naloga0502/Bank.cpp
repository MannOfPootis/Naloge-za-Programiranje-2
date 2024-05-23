//
// Created by doominik on 4.4.2024.
//

#include "Bank.h"
#include "sstream"
#include "Date.h"
#include <typeinfo>
#include <iostream>
#include "SavingsAccount.h"
Bank::Bank()  {}

void Bank::addAccount(Account *account) {
    accounts.push_back(account);

}

std::vector<Account *> Bank::getAccounts(Person *person) {
    std::vector<Account*> box;
    for(int i =0;i<accounts.size();i++){
        if(accounts[i]->getOwner()==person){
            box.push_back(accounts[i]);
        }
    }

    return box;
}

bool Bank::makeDepositOnAccount(double amount, uint number) {
    for(int i =0;i<accounts.size();i++){
        if(accounts[i]->getNumber()==number){
            if(accounts[i]->makeDeposit(amount)){
                transactions.push_back(Transaction(accounts[i]->getNumber(),Date::getTodysDate(),amount));
                return true;
            }

        }
    }
    return false;
}
bool Bank::makeWithdrawlOnAccount(double amount, uint number) {
    for(int i =0;i<accounts.size();i++){
        if(accounts[i]->getNumber()==number){
            if(accounts[i]->makeWithdrawl(amount)){
                transactions.push_back(Transaction(accounts[i]->getNumber(),Date::getTodysDate(),-amount));
                return true;
            }
        }
    }
    return false;
}

std::string Bank::toString() {
    std::stringstream ss;

    for(int i =0;i<accounts.size();i++){
        ss<<accounts[i]->toString()<<"\n";
    }
    return ss.str();
}

void Bank::applyIneterest() {
    if(Date::getTodysDate().getDay()==1){
        for(int i=0;i<accounts.size();i++){
            if(typeid(accounts[i]).name()=="SavingsAccount")
            {
                SavingsAccount diftype= (SavingsAccount &) accounts[i];
                accounts[i]->makeDeposit(diftype.getIntrestRate()*accounts[i]->getBalance());
            }
        }
    }

}

Bank::~Bank() {
    for(int i=0;i<accounts.size();i++){
        delete accounts[i];
    }


}

void Bank::getTransactionsByAccount(unsigned int accountNumber) {
    for(int i =0;i<transactions.size();i++){
        if(transactions[i].getAccountNumber()==accountNumber){
            std::cout<<transactions[i].toString()<<"\n";
        }
    }
}



