#ifndef _MYBANK_H_
#define _MYBANK_H_

    void openNewAccount(double amount);
    void balance(int accountNumber);
    void deposit(int accountNumber,double amount);
    void withdrawal(int accountNumber,double amount);
    void closeAccount(int accountNumber);
    void addInterest(double rate);
    void printAll();
    void closeAllAccounts();
    double twoNumsAfterThePoint(double amount);
#endif
