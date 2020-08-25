/**
 * \class CreditCardSystem.h
 * Containts the basic elements of the system (like a transaction and the method of storing the transaction)
 * \author $Rupin Mittal $
 * \date $Date: 8/20/20
 */

#ifndef CREDITCARDSYSTEM_H  //guard against infinite loop of includes
#define CREDITCARDSYSTEM_H

#include <stdlib.h>
#include <stdio.h>

#define NUM_GENTRANSACTIONS 30
#define MAX_TRANSACTIONS 100                    //maximum of 100 transactions can be held

struct transaction   //the struct that will represent the transactions
{
    int amount;
    char location[9];
    char date[9];
};              
extern struct transaction record[];     //the array of structs that holds all the transactions
extern int numTransactions;             //the number of transactions in the record

#endif