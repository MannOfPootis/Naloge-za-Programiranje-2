#include <iostream>
#include "Bank.h"
#include "SavingsAccount.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Person joško("jožef" ,"štefan");
    Account zaBiznis(&joško, 1,69.69);
    zaBiznis.makeDeposit(10);
    std::cout<<zaBiznis.toString();
    SavingsAccount zaAvto(&joško,11,9999,0.01);
    Bank nlb;
    nlb.addAccount(new SavingsAccount(&joško,11,9999,0.01));
    nlb.addAccount(new     Account(&joško, 1,69.69)
    );
    std::cout<<nlb.toString();
    nlb.makeDepositOnAccount(10,1);
    nlb.makeWithdrawlOnAccount(10,11);

    nlb.makeWithdrawlOnAccount(1000,11);
    std::cout<<"\n";
    nlb.getTransactionsByAccount(1);

    nlb.getTransactionsByAccount(11);


    std::cout<<nlb.toString();






    return 0;
}
