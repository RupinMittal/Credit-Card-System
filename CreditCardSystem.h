#ifndef CREDITCARDSYSTEM_H  //guard against infinite loop of includes
#define CREDITCARDSYSTEM_H

#include <stdlib.h>
#include <stdio.h>

#define NUM_TRANSACTIONS 30
#define MAX_TRANSACTIONS 100                    //maximum of 100 transactions can be held

struct transaction   //the struct that will represent the transactions
{
    int amount;
    char location[9];
    char date[7];
};              
extern struct transaction record[];     //the array of structs that holds all the transactions

#endif