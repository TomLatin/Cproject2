
#include <stdio.h>
#include "myBank.h"
char choice = ' ';
int main()
{
    printf("If you want to open a new account please click O\n If you want to see your balance please click B\n If you want to make a deposit please press D\n If you want to withdraw please press W\n If you want to close your account please press C\n If you want to add interest at a given percentage rate to all open accounts,\n please click I\n If you want to print all open accounts and their balance,please click P\n If you want to close all accounts and exit the program, press E\n");

    do
    {
        if(scanf(" %c", &choice) != 1){
            printf("failed to get char\n");
        }
        
        switch (choice)
        {
        case 'O':
        {
            double amount=0;
            printf("Please enter the amount you would like to deposit:\n");
            if((scanf("%lf",&amount)!=1)||(amount<0))
             {
              printf("This operation failed because you did not enter a proper positive number\n");
             } 
            else
            {
             openNewAccount(amount);
            }
        }
            break;
        
         case 'B':
         {
            int accountNumber=0;
            printf("Please enter your account number: \n");
            if((scanf("%d",&accountNumber)!=1)||(!(accountNumber>=901&&accountNumber<=950)))
             {
              printf("This operation failed because you did not enter your account number properly,The account number can range from 901-950 only\n");
             } 
            else
            {
                balance(accountNumber);
            }
        }
            break;

         case 'D':
       {
            int accountNumber=0;
            double amount=0;
            printf("Please enter your account number first and then Please enter the amount you would like to deposit:\n");
            if((scanf("%d %lf",&accountNumber , &amount)!=2)||(amount<0)||(!(accountNumber>=901&&accountNumber<=950)))
             {
              printf("This operation failed because you did not enter your account number properly,The account number can range from 901-950 only,\nor you did not enter a proper deposit amount\n ");
             } 
             else
             {
               deposit(accountNumber,amount);
             }
        }     
            break;
        case 'W':
        {
            int accountNumber=0;
            double amount=0;
            printf("Please enter your account number and then Please enter the amount you would like to withdrawal:\n");
            if((scanf("%d %lf",&accountNumber , &amount)!=2)||(amount<0)||(!(accountNumber>=901&&accountNumber<=950)))
             {
              printf("This operation failed because you did not enter your account number properly,The account number can range from 901-950 only,\nor you did not enter a good amount for withdrawal\n");
             } 
            else
            {
                withdrawal(accountNumber,amount);
            }
        }    
            break;  

        case 'C':
        {
            int accountNumber;
            printf("Please enter your account number:\n");
            if(scanf("%d",&accountNumber)!=1||(!(accountNumber>=901&&accountNumber<=950)))
             {
              printf("This operation failed because you did not enter your account number properly,The account number can range from 901-950 only\n");
             } 
             else
             {
                closeAccount(accountNumber);
             }
        }     
            break; 

        case 'I':
        {
            double rate;
            printf("Please enter interest at a given percentage rate:\n");
            if((scanf("%lf",&rate)!=1)||(rate<0))
             {
              printf("The operation failed because you did not enter a proper positive percentage\n");
             } 
            else
            {
               addInterest(rate);
            }
        }   
            break;  

        case 'P':printAll();
            break; 

        case 'E':closeAllAccounts();  
            break;    
        
        default: printf("ERR:invalid input choose action: O,B,W,D,I,P,E \n ");
            break;
        }
        if(choice != 'E') printf("\nchoose action: O,B,W,D,I,P,E\n");   
    } while (choice!='E');
    
    return 0;
}