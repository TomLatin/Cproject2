#include <stdio.h>
#include "myBank.h"
#define LINE 2
#define ROW 50
#define OPEN 1.0
#define CLOSE 0.0

static double accounts [LINE][ROW]={0};

void openNewAccount(double amount)
{
    double num=twoNumsAfterThePoint(amount);
    int i=1;
    int flag=0;
    for(i=1;i<51&&(flag==0);i++)
    {
        if(accounts[0][i-1]==CLOSE)
        {
            printf("The acount number is:%d " ,900+i);
            accounts[0][i-1]=OPEN;
            accounts[1][i-1]=num;
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("Our bank has no room for a new account");
    }
}

void balance(int accountNumber)
{
    if(accounts[0][accountNumber-901]==OPEN)
    {
        printf("Your balance is: %0.2lf",accounts[1][accountNumber-901]);
    }

    else
    {
        printf("Your bank account is closed");
    }
    
}

void deposit(int accountNumber,double amount)
{
     if(accounts[0][accountNumber-901]==OPEN)
    {
        double num=twoNumsAfterThePoint(amount);
        accounts[1][accountNumber-901]+=num;
        printf("Your balance is: %0.2lf",accounts[1][accountNumber-901]);
    }
     else
    {
        printf("Your bank account is closed");
    }
}
void withdrawal(int accountNumber,double amount)
{
    
    if(accounts[0][accountNumber-901]==OPEN)
    {
        double num=twoNumsAfterThePoint(amount);
        if(accounts[1][accountNumber-901]>=num)
        {
         accounts[1][accountNumber-901]-=num;
        printf("Your balance is: %0.2lf",accounts[1][accountNumber-901]);
        }
        else
        {
             printf("You can withdraw up to that amount: %0.2lf",accounts[1][accountNumber-901]);
        }
        
    }

     else
    {
        printf("Your bank account is closed");
    }
}
void closeAccount(int accountNumber)
{
     if(accounts[0][accountNumber-901]==OPEN)
     {
         accounts[0][accountNumber-901]=CLOSE;
         accounts[1][accountNumber-901]=0.0;
     }
    else
    {
        printf("Your bank account was already closed");
    }
}

void addInterest(double rate)
{
    int i=1;
    for(i=1;i<51;i++)
    {
        if(accounts[0][i-1]==OPEN)
        {
            accounts[1][i-1]+=((rate*accounts[1][i-1])/(double)100);
        }
    }
}

void printAll()
{
    int i=1;
    for(i=1;i<51;i++)
    {
        if(accounts[0][i-1]==OPEN)
        {
            printf("The acount number is:%d, and the balance in the bank account is:%0.2f \n" ,900+i,accounts[1][i-1]);
        }
    }
}

void closeAllAccounts()
{
    int i=1;
    for(i=1;i<51;i++)
    {
         accounts[0][i-1]=CLOSE;
         accounts[1][i-1]=0.0;
    }

}

double twoNumsAfterThePoint(double amount)
{
    amount=amount*100;
    amount=((int)amount)/(double)100;
    return amount;
}
