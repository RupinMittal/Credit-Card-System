/**
 * \class RecordGetter.c
 * This class gets the initial set of Transactions from the file and stores them
 * \author $Rupin Mittal $
 * \date $Date: 8/21/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "CreditCardSystem.h"

#define MAX_TRANSACTIONS 100                    //maximum of 100 transactions can be held

struct transaction record[MAX_TRANSACTIONS];    //define the arary of structs of transactions

void getRecord()
{
    FILE *recordPtr;                        //the pointer to the record.txt file
    int localAmount;                        //local copy of an amount
    char localLocation[10], localDate[8];    //local copies of a location and date
    
    recordPtr = fopen("Record.txt", "r");   //initialize pointer for the input file

    if(recordPtr != NULL)
    {
        for(int i = 0; i < NUM_TRANSACTIONS; i++)
        {
           fscanf(recordPtr, "%d", &localAmount);                   //store amount in localAmount
           record[i].amount = localAmount;                          //put each amount in each struct

           fgets(localLocation, 10, recordPtr);                     //local localLocation with the location
           for(int k = 0; k < 9; k++)
                record[i].location[k] = localLocation[k];           //local struct with the location

           fgets(localDate, 8, recordPtr);                          //local localLocation with the location
           for(int k = 0; k < 7; k++)
                record[i].date[k] = localDate[k];                   //local struct with the location
        }
    }
    else
    {
        printf("Could not read from file");
    }
    /*
    for(int i = 0; i < NUM_TRANSACTIONS; i++)
    {
        printf("%d\n", record[i].amount);
        printf("%s", record[i].location);
        printf("%s", record[i].date);
    }
    */
}