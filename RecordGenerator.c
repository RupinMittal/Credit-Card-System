#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randomAmount()
{
    return (rand() % 2000);     //return an amount from $0 - $2000
}
int main()
{
    
    FILE *recordPtr;    //the pointer to the record.txt file

    recordPtr = fopen("Record.txt", "w");

    if(recordPtr != NULL)
    {
        srand(time(0));             //set the seed based on the time since Jan 1, 1970 (Unix timestamp)
        for(int i = 0; i < 10; i++)
            fprintf(recordPtr, "%d\n", randomAmount());
    }
    else
    {
        printf("Could not write to file\n");
    }
    fclose(recordPtr);

    return 0;
}