/**
 * \class RecordGenerator.c
 * This generates the initial set of Transactions to be stored
 * \author $Rupin Mittal $
 * \date $Date: 8/20/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "RecordHeader.h"
#include "CreditCardSystem.h"

struct transaction record[MAX_TRANSACTIONS];    //define the arary of structs of transactions

///method to generate the record into the Record.txt file
void generateRecord()
{
    int localAmount;         //int to hold the local copy of amount
    char localLocation[9];   //array that will hold the location
    char *ptrLocation;       //the pointer to the array with the location
    char localDate[9];       //array that will hold the date
    char *ptrDate;           //the pointer to array with the date

    ptrLocation = localLocation;                 //initialize pointer for the array with location
    ptrDate = localDate;                         //initialize pointer for the array with date

    srand(time(0));             //set the seed based on the time since Jan 1, 1970 (Unix timestamp)
    for(int i = 0; i < NUM_GENTRANSACTIONS; i++)
    {
        localAmount = randomAmount(0, 2000);                   //get random amount
        randomLocation(ptrLocation);                            //fill location with random location
        randomDate(ptrDate);                                    //fill date with random date

        record[i].amount = localAmount;                         //put amount into struct into array
        for(int k = 0; k < 9; k++)
            record[i].location[k] = localLocation[k];           //load struct with the location
        for(int k = 0; k < 9; k++)
                record[i].date[k] = localDate[k];               //load struct with the location
    }
}

///Returns a random amount between $lower - $higher 
int randomAmount(int lower, int higher)
{
    return ((rand() % (higher - lower)) + lower);     //return an amount from $lower - $higher
}

///fills the passed array with a location
void randomLocation(char *location)
{
    int randLocationNumber, rows, columns;                                          //a randomly chosen location. The number is the row number in the array locations
    char locations[6][9] = {{'C', 'h', 'i', 'p', 'o', 't', 'l', 'e', '\0'},         //the various locations
                          {'C', 'o', 's', 't', 'c', 'o', '\0', '\0', '\0'}, 
                          {'T', 'a', 'r', 'g', 'e', 't', '\0', '\0', '\0'}, 
                          {'N', 'i', 'k', 'e', '\0', '\0', '\0', '\0', '\0'},
                          {'A', 'm', 'a', 'z', 'o', 'n', '\0', '\0', '\0'},
                          {'R', 'a', 'l', 'p', 'h', '\'', 's', '\0', '\0'}};
    
    rows = sizeof(locations) / sizeof(locations[0]);                //number of rows is total array size / size of one row
    columns = sizeof(locations[0]) / sizeof(locations[0][0]);       //number of columns is size of one row / size of one element in row

    randLocationNumber = (rand() % rows);       //random location from 0 - last row
    
    for(int i = 0; i < columns; i++)
        *(location + i) = *(*(locations + randLocationNumber) + i);      //fill the passed array with the location
}

///returns integer with the date in mmddyy format
void randomDate(char *date)
{
    int randMonth, randDay, randYear;           //the variables for the random values

    randMonth = (rand() % 12) + 1;              //months between 1-12
    if(randMonth == 2)                          
        randDay = (rand() % 28) + 1;            //if the month is Feb, the days are from 1-28
    else
        randDay = (rand() % 30) + 1;            //otherwise days are from 0-30
    randYear = (rand() % 20) + 1;               //years from 0-20 (last 20 years)

    if(randMonth < 10)                                  //if less than 10, enter as 0_ (still has to be mm)
    {
        *(date + 0) = '0';
        *(date + 1) = (char)(48 + randMonth);
    }
    else                                                //otherwise enter it normally
    {
        *(date + 0) = '1';
        *(date + 1) = (char)(48 + (randMonth % 10));
    }

    *(date + 2) = '/';

    if(randDay < 10)                                    //if less than 10, enter as 0_ (still has to be d)
    {
        *(date + 3) = '0';
        *(date + 4) = (char)(48 + randDay);
    }
    else                                                //otherwise enter it normally
    {
        *(date + 3) = (char)(48 + (randDay / 10));
        *(date + 4) = (char)(48 + (randDay % 10));
    }

    *(date + 5) = '/';

    if(randYear < 10)                                  //if less than 10, enter as 0_ (still has to be yy)
    {
        *(date + 6) = '0';
        *(date + 7) = (char)(48 + randYear);
    }
    else                                                //otherwise enter it normally
    {
        *(date + 6) = (char)(48 + (randYear / 10));
        *(date + 7) = (char)(48 + (randYear % 10));
    } 
    *(date + 8) = '\0';                                 //last char in char[] should be '\0'
}