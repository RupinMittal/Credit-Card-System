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

//function declarations
int compareDate(int firstIndex, int secondIndex, int direction);
int compareAmount(int firstIndex, int secondIndex, int direction);
void quickSort(int (*fPtr)(int, int, int), int direction, int left, int right);
void swap(int index1, int index2);
int partition(int (*fPtr)(int, int, int), int direction, int left, int right);

///function to call the appropriate sorting function based on what the user wants (called in Keeper file)
///@param int 1 (date) and 2 (amount)
///@param int 1 (old/new and cheap/expensive) -1 (new/old and expensive/cheap)
void sortRecord(int type, int direction)
{
    if(type == 1)       //sort by date
    {
        quickSort(compareDate, direction, 0, numTransactions - 1);
        if(direction == 1)
            printf("Your record has been sorted by date from oldest to newest\n");
        else
            printf("Your record has been sorted by date from newest to oldest\n"); 
    }
    else                //sort by amount
    {
        quickSort(compareAmount, direction, 0, numTransactions - 1);  
        if(direction == 1)
            printf("Your record has been sorted by amount from lowest to highestt\n");
        else
            printf("Your record has been sorted by date from lowest to highest\n"); 
    }       
}

///swap helper function for sorting
void swap(int index1, int index2)
{
    struct transaction temp;    //variable that holds one of the structs to be swapped temporarily

    temp = record[index1];              //the actual swap
    record[index1] = record[index2];
    record[index2] = temp;
}

///function that finds the Partition index and does the swaps
///Partitioning finds the pivot, and rearranges the array so elements smaller than the pivot are to the left, and larger are to the left
int partition(int (*fPtr)(int, int, int), int direction, int left, int right)
{
    int partitionIndex, pivotIndex;      //the partitionIndex and the index of the pivot

    pivotIndex = right;                 //the pivot will be the last element in the array
    partitionIndex = left;              //the partitionIndex starts at the start or the array

    for(int i = left; i < right; i++)           //for every elemt from the start to right before the index
    {
        if(fPtr(i, right, direction) < 0)       //if the element is less than the pivot
        {
            swap(i, partitionIndex);            //that element with the element at the partitionIndex
            partitionIndex++;                   //and increment the partition index
        }
    }

    //after all the elements less than the pivot are on the right and the pivot and the greater elements are on the left, put the pivot
    //in its correct position by swapping it with the partitionIndex and return this position
    swap(partitionIndex, pivotIndex);           
    return partitionIndex;
}

///function to actually do the sorting
///@param (*p)(int, int, int) (the function to use for comparing)
///@param int the direction (1 (old/new and cheap/expensive) -1 (new/old and expensive/cheap))
void quickSort(int (*fPtr)(int, int, int), int direction, int left, int right)
{
    int partitionIndex;     //the partition index

    if(left < right)        //sorting needs to happen
    {
        partitionIndex = partition(fPtr, direction, left, right);    //get the location where the pivot ended up (the position of the element in its correct place)
        quickSort(fPtr, direction, left, partitionIndex - 1);        //recursively sort left side
        quickSort(fPtr, direction, partitionIndex + 1, right);       //recursively sort right side
    }
}

///function to find out if transaction at first index is chronologically before or after the second one
///@param int direction (1 if you want oldest to newest and -1 if you want newest to oldest)
///@return int 1 if firstIndex is newer than secondIndex, -1 if first index is older. if direction param, this is switched
int compareDate(int firstIndex, int secondIndex, int direction)
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
///@param int direction (1 if you want cheap to expensive and -1 if you want expensive to cheap)
///@return int 1 if firstIndex is more expensive than secondIndex, -1 if first index is cheaper. if direction param, this is switched
int compareAmount(int firstIndex, int secondIndex, int direction)
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