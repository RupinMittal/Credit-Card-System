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

void printMenu();

int main()
{
    generateRecord();
    printRecordToFile();
    printRecordToSystem();
    printMenu();

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
}