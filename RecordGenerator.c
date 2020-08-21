#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *recordPtr;    //the pointer to the record.txt file

    recordPtr = fopen("Record.txt", "w");

    if(recordPtr != NULL)
    {
        fprintf(recordPtr, "YEET, It worked!");
    }
    else
    {
        printf("Could not write to file\n");
    }
    fclose(recordPtr);

    return 0;
}