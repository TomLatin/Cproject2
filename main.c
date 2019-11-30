
#include <stdio.h>
#include "myBank.h"
char choice = ' ';//The action the user will selected
int main()
{
    printf("If you want to open a new account please click O\n If you want to see your balance please click B\n If you want to make a deposit please press D\n If you want to withdraw please press W\n If you want to close your account please press C\n If you want to add interest at a given percentage rate to all open accounts,\n please click I\n If you want to print all open accounts and their balance,please click P\n If you want to close all accounts and exit the program, press E\n");

    do
    {
         //Receives a character signifying bank action
        if(scanf(" %c", &choice) != 1){
            printf("failed to get char\n");
        }
        
        switch (choice)
        {
        /*
        In case the user gives the character O then the system needs to open a new account,
        as long as the system receives a valid positive amount in order to deposit in the new account,otherwise the operation will fail.
        */   
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
             openNewAccount(amount); //Opening an account is only possible if the bank does not have 50 open accounts
            }
        }
            break;
        /*
         In case the user gives the character B then the system should show to the user the balance in his bank account,
         as long as the user has entered a valid account number between 901-950 only,otherwise the operation will fail.
        */
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
                balance(accountNumber);//This operation is only allowed if the bank account is open
            }
        }
            break;
        /*
        In case the user gives the character D then the system needs to deposit the amount the user gave to his account,
        as long as the user has entered a valid account number between 901-950 only, 
        and The amount that the user gave is positive and valid,otherwise the operation will fail.
        */
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
               deposit(accountNumber,amount);//This operation is only allowed if the bank account is open
             }
        }     
            break;

        /*
         In case the user gives the character W then the system needs to withdraw the money from his bank account.
        as long as the user has entered a valid account number between 901-950 only, 
        and The amount that the user gave is positive and valid and also not greater than the amount he has in his bank account,
        otherwise the operation will fail.
        */ 
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
                withdrawal(accountNumber,amount);//This operation is only allowed if the bank account is open and the user have enough money.
            }
        }    
            break;  
        /*
         In case the user gives the character C then the system needs to close his bank account.
        as long as the user has entered a open valid account number between 901-950 only,otherwise the operation will fail.
        */ 
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
                closeAccount(accountNumber);///This operation is only allowed if the bank account is open
             }
        }     
            break; 

       /*
         In case the user gives the character I then the system needs add interest at a discounted rate to all open accounts.
        as long as the user has entered a valid and positive rate,otherwise the operation will fail.
        */ 
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
        /*
         In case the user gives the character I then the system needs to print all open accounts and the balance of these accounts.
        */
        case 'P':printAll();
            break; 
        /*
         In case the user gives the character E then the system needs to close all open accounts and exsite the program.
        */
        case 'E':closeAllAccounts();  
            break;    
        
        default: printf("ERR:invalid input choose action: O,B,W,D,I,P,E \n ");
            break;
        }
        if(choice != 'E') printf("\nchoose action: O,B,W,D,I,P,E\n");   
    } while (choice!='E');
    
    return 0;
}