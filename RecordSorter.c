/**
 * \class RecordSorter.c
 * This sorts the record as per the user's request
 * \author $Rupin Mittal $
 * \date $Date: 8/24/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "RecordHeader.h"
#include "CreditCardSystem.h"

///function to find out if transaction at first index is chronologically before or after the second one
///@param int direction (1 if you want oldest to newest and -1 if you want newest to oldest)
///@return int 1 if firstIndex is newer than secondIndex, -1 if first index is older. if direction param, this is switched
int sortDate(int firstIndex, int secondIndex, int direction)
{
    int result;                                     //answer being returned
    int year1, month1, day1, year2, month2, day2;   //information for both the dates 

    //the info is converted into ints by typecasting, so if the the year is listed as 12, year1 will store 4950
    year1 = ((int)(record[firstIndex].date[6]) * 100) + (int)(record[firstIndex].date[7]);
    year2 = ((int)(record[secondIndex].date[6]) * 100) + (int)(record[secondIndex].date[7]);
    month1 = ((int)(record[firstIndex].date[0]) * 100) + (int)(record[firstIndex].date[1]);
    month2 = ((int)(record[secondIndex].date[0]) * 100) + (int)(record[secondIndex].date[1]);
    day1 = ((int)(record[firstIndex].date[3]) * 100) + (int)(record[firstIndex].date[4]);
    day2 = ((int)(record[secondIndex].date[3]) * 100) + (int)(record[secondIndex].date[4]);

    if(year1 > year2)
        result = 1;
    else
        if(year1 < year2)                           //if neither of these are true, then years are equal
            result = -1;
        else
            if(month1 > month2)
                result = 1;
            else
                if(month1 < month2)                 //if neither of these are true, then months and years are equal
                    result = -1;
                else
                    if(day1 > day2)
                        result = 1;
                    else
                        if(day1 < day2)             //if neither of these are true, then dates are identical
                            result = -1;
                        else
                            result = 0;             //so don't switch regardless of new-->old or old-->new

    if(direction == -1)     //if the direction is new-->old instead of old-->new
        result *= -1;       //switch result

     return result;
}

///function to find out if transaction at first index is chronologically before or after the second one
///@param int direction (1 if you want cheap to expense and -1 if you want expensive to cheap)
///@return int 1 if firstIndex is more expensive than secondIndex, -1 if first index is cheaper. if direction param, this is switched
int sortAmount(int firstIndex, int secondIndex, int direction)
{
    int result;         //the answer to be return to the user

    if((record[firstIndex].amount - record[secondIndex].amount) > 0)            //if amount in first > amount in second
        result = 1;
    else
        if((record[firstIndex].amount - record[secondIndex].amount) < 0)        //if amount in second > amount in first
            result = -1;
        else        
            result = 0;                                                         //if the amounts are equal, don't switch

    if(direction == -1)                                 //if direction is expensive-->cheap instead of cheap-->expensive
        result *= -1;                                   //switch result

    return result; 
}