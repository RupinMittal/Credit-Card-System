/**
 * \class RecordPrinter.c
 * This prints the list of Transactions in the format user would like
 * \author $Rupin Mittal $
 * \date $Date: 8/21/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "CreditCardSystem.h"
#include "RecordHeader.h"

//prints the record out to the file Record.txt
void printRecordToFile()
{
    FILE *recordPtr;                        //the pointer to the record.txt file
    
    recordPtr = fopen("Record.txt", "w");   //initialize pointer for the input file

    if(recordPtr != NULL)
    {
        fprintf(recordPtr, "                 Amount       Date   Location\n");
        for(int i = 0; i < numTransactions; i++)
        {
           fprintf(recordPtr, "Transaction %2d:", (i + 1));
           fprintf(recordPtr, "  $%5d", record[i].amount);                 //print amount to file
           fprintf(recordPtr, "%11s", record[i].date);                   //print amount to file
           fprintf(recordPtr, "%11s\n", record[i].location);               //print amount to file
        }
    }
    else
    {
        printf("Could not write to file");         //if we could not find the file pointer
    }
    fclose(recordPtr);              //close the file
    printf("Your record has been printed to the Read.txt file\n");
}

//prints the record out to the system
void printRecordToSystem()
{
    printf("Your record has been printed below:\n");
    printf("\n*************************************************\n");
    printf("                 Amount       Date   Location\n");
    for(int i = 0; i < numTransactions; i++)
    {
       printf("Transaction %2d:", (i + 1));
       printf("  $%5d", record[i].amount);                 //print amount to file
       printf("%11s", record[i].date);                     //print amount to file
       printf("%11s\n", record[i].location);               //print amount to file
    }
    printf("\n*************************************************\n");
}