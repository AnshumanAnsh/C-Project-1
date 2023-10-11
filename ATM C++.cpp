#include<stdio.h>
#include<windows.h>
#include<time.h>



int main(){

   int pin=2004,option,entered_pin,count=0,amount=1;//functions are defined here

   float balance=175000;

   int continue_transaction=1;



   time_t now;

   time(&now);

   printf("\n");

   printf("\t\t\t\t\t       %s",ctime(&now));//current time and date will be appear at the top

   printf("\n\t\t\t******************WELCOME TO ANSHUMAN DASH BANK ATM*******************");



   while(pin !=entered_pin){

     printf("\nPlease enter your pin :");

     scanf("%d",&entered_pin);

     if(entered_pin !=pin){

       Beep(500,450);

       printf("Invalid pin!!!");

     }

     count++;

     if(count==3 && pin != entered_pin){

      exit(0);

    }

   }

    while(continue_transaction !=0){

   printf("\n\t\t\t*************Available Transaction************");

   printf("\n\n\t\t1.Withdrawl");

   printf("\n\t\t2.Deposit");

   printf("\n\t\t3.Check Balance");

   printf("\n\n\t4.Please select the option :");

   scanf("%d",&option);

   switch(option){



     case 1:



            printf("\n\t\tEnter the amount : ");

            scanf("%d",&amount);

            if(balance< amount){

            printf("\n\t Sorry insufficient balance");

            amount =1;

            break;

        }

        else{

             balance -=amount;

             printf("\n\t\tYou have withdraw Rs.%d. Your new balance is %.2f",amount,balance);

             amount=1;

             break;

     case 2:

            printf("\n\t\t Please enter the amount : ");

            scanf("%d",&amount);

            balance +=amount;

            printf("\n\t\tYou have deposited rs.%d. Your new balance is %2f",amount,balance);

            printf("\n\t\t****************** Thank you for banking with Anshuman******************");

            amount=1 ;

            break;

     case 3:

            printf("\n\t\t Your balance is Rs.%.2f",balance);

            break;

    default:

        Beep(500,450);

        printf("\n\t\tInvalid Option!!!");



    }

   }



    printf("\n\t\tDo you wish to perform another transaction ?Press 1[Yes], 0[No]");

    scanf("%d",&continue_transaction);



   }

}
