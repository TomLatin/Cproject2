#include <stdio.h>
#include "myBank.h"

double accounts[LINE][ROW]={0};


/*
The function goes over all accounts, on the first closed account it opens and puts the initial deposit amount into it
*/
void openNewAccount(double amount)
{
    double num=twoNumsAfterThePoint(amount);//Saves the amount with just two digits after the point
    int i=1;
    int flag=0;
    for(i=1;i<51&&(flag==0);i++)
    {
        if(accounts[0][i-1]==CLOSE)
        {
            printf("The acount number is:%d \n" ,900+i);
            accounts[0][i-1]=OPEN;
            accounts[1][i-1]=num;
            flag=1;
        }
    }
    /*
    If the function did not find a closed account, 
    i.e. all 50 open accounts it notifies the user that there is no room in the bank for a new account
    */
    if(flag==0)
    {
        printf("Our bank has no room for a new account\n");
    }
}
/*
The function checks whether the account is open and if so it prints the balance of the account.
Otherwise it prints that the account is closed
*/
void balance(int accountNumber)
{
    if(accounts[0][accountNumber-901]==OPEN)
    {
        printf("Your balance is: %0.2lf\n",accounts[1][accountNumber-901]);
    }

    else
    {
        printf("Your bank account is closed\n");
    }
    
}
/*
The function checks whether the account is open and if so adds the amount to the account balance.
Otherwise it prints that the account is closed
*/
void deposit(int accountNumber,double amount)
{
     if(accounts[0][accountNumber-901]==OPEN)
    {
        double num=twoNumsAfterThePoint(amount);//Saves the amount with just two digits after the point
        accounts[1][accountNumber-901]+=num;
        printf("Your balance is: %0.2lf\n",accounts[1][accountNumber-901]);
    }
     else
    {
        printf("Your bank account is closed\n");
    }
}
/*
The function checks whether the account is open, then it checks whether the amount to be withdrawn is no
greater than the amount in the bank account if it withdraws otherwise it prints an error message.
If the account is closed the function prints that this account is closed
*/
void withdrawal(int accountNumber,double amount)
{
    
    if(accounts[0][accountNumber-901]==OPEN)
    {
        double num=twoNumsAfterThePoint(amount);//Saves the amount with just two digits after the point
        if(accounts[1][accountNumber-901]>=num)
        {
         accounts[1][accountNumber-901]-=num;
        printf("Your balance is: %0.2lf\n",accounts[1][accountNumber-901]);
        }
        else
        {
             printf("You can withdraw up to that amount: %0.2lf\n",accounts[1][accountNumber-901]);
        }
        
    }

     else
    {
        printf("Your bank account is closed\n");
    }
}
/*
The function checks whether the account is open If so the function closes the account and resets the account balance,
otherwise it prints that the account is closed.
*/
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
/*
The function goes over all accounts,
each open account adds the percentage interest rate to it
*/
void addInterest(double rate)
{
    int i=1;
    for(i=1;i<51;i++)
    {
        if(accounts[0][i-1]==OPEN)
        {
            double num=twoNumsAfterThePoint((rate*accounts[1][i-1])/(double)100);//Saves the amount with just two digits after the point
            accounts[1][i-1]+=num;
        }
    }
}
/*
The function goes over all accounts, 
if it finds an account that is open then it prints the account number and the balance of that account
*/
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
/*
The function goes over all accounts, 
if it finds an account that is open then it closes the bank account and resets the balance
*/
void closeAllAccounts()
{
    int i=1;
    for(i=1;i<51;i++)
    {
         accounts[0][i-1]=CLOSE;
         accounts[1][i-1]=0.0;
    }

}
/*
An assistance function whose function is to save the number with only two numbers after the point
*/
double twoNumsAfterThePoint(double amount)
{
    amount=amount*100;
    amount=((int)amount)/(double)100;
    return amount;
}
