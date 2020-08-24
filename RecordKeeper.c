/**
 * \class RecordKeeper.c
 * This class manages the set of transactions
 * \author $Rupin Mittal $
 * \date $Date: 8/21/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "RecordHeader.h"
#include "CreditCardSystem.h"

int numTransactions = NUM_GENTRANSACTIONS;     //the initial number of transactions

//function declarations
void printMenu();
void addTransaction();;

int main()
{
    int option;             //the user's option
    generateRecord();       //generate the initial record

    option = 0;             //initially, while loop is run at least once

    while(option != 8)      //runs the loop for the program
    {
        printMenu();
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printRecordToSystem();
                break;
            case 2:
                printRecordToFile();
                break;
            case 3:
                //sortDateNewest();
                break;
            case 4:
                //sortDateOldest();
                break;
            case 5:
                //sortAmountHighest();
                break;
            case 6:
                //sortAmountLowest();
                break;
            case 7:
                addTransaction();
                break;
            case 8:
                break;
        }
    }

    return 0;
}

//function to print the menu options for user
void printMenu()
{
    printf("\n***************************************************************\n");
    printf("Press 1 to --> Print your record to the system\n");
    printf("Press 2 to --> Print your record to the .txt file\n");
    printf("Press 3 to --> Sort the record by date (newest to oldest)\n");
    printf("Press 4 to --> Sort the record by date (oldest to newest)\n");
    printf("Press 5 to --> Sort the record by amount (highest to lowest)\n");
    printf("Press 6 to --> Sort the record by amount (lowest to highest)\n");
    printf("Press 7 to --> Add a transaction\n");
    printf("Press 8 to --> Leave the program\n");
    printf("***************************************************************\n\n");
    printf("Enter your choice here --> ");
}

//function to add a user-added Transaction to the record
void addTransaction()
{
    int userAmount;         //the amount the user enters 
    char userDate[9];       //the date the user enters
    char userLocation[9];   //the location that the user enters

    printf("\nPlease enter the transaction amount --> ");
    scanf("%d", &userAmount);
    printf("Please enter the date in mm/dd/yy format --> ");
    scanf("%s", userDate);
    printf("Please enter the first 9 nine letters of the location --> ");
    scanf("%s", userLocation);

    record[numTransactions].amount = userAmount;                         //put amount into struct into array
    for(int k = 0; k < 9; k++)
        record[numTransactions].location[k] = userLocation[k];           //load struct with the location
    for(int k = 0; k < 9; k++)
            record[numTransactions].date[k] = userDate[k];               //load struct with the location
        
    numTransactions++;      //inrement the number of transactions

    printf("Your transaction has been recorded\n");
}
