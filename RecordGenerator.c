/**
 * \class RecordGenerator.c
 * This class generates the initial set of Transactions to be stored
 * \author $Rupin Mittal $
 * \date $Date: 8/20/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

int main()
{
    
    FILE *recordPtr;    //the pointer to the record.txt file
    char location[9];   //array that will hold the location
    char *ptrLocation;  //the pointed to the array with the location

    recordPtr = fopen("Record.txt", "w");   //initialize pointer for the output file
    ptrLocation = location;                 //initialize pointer for the array with location

    if(recordPtr != NULL)
    {
        srand(time(0));             //set the seed based on the time since Jan 1, 1970 (Unix timestamp)
        for(int i = 0; i < 20; i++)
        {
            fprintf(recordPtr, "%d\n", randomAmount(0, 2000));      //print random amount
            randomLocation(ptrLocation);                            //fill location with random location
            fprintf(recordPtr, "%s\n", location);                   //print the random location
        }      
    }
    else
    {
        printf("Could not write to file\n");
    }
    fclose(recordPtr);

    return 0;
}