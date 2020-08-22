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
    getRecord();

    return 0;
}