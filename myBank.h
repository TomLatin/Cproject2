#ifndef _MYBANK_H_
#define _MYBANK_H_
#define LINE 2
#define ROW 50
#define OPEN 1.0
#define CLOSE 0.0

extern double accounts[LINE][ROW];

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
