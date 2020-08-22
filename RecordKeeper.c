/**
 * \class RecordKeeper.c
 * This class manages the set of transactions
 * \author $Rupin Mittal $
 * \date $Date: 8/21/20
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "RecordHeader.h"
#include "CreditCardSystem.h"

int main()
{
    generateRecord();

    printf("This is proof it works -->%d\n", record[0].amount);

    return 0;
}