/**
 * \class RecordHeader.c
 * Containts the methods used to keep track of the record
 * \author $Rupin Mittal $
 * \date $Date: 8/20/20
 */

#ifndef RECORDHEADER_H  //guard against infinite loop of includes
#define RECORDHEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//functions in RecordGenerator
void generateRecord();
int randomAmount(int lower, int higher);
void randomLocation(char *location);
void randomDate(char *date);

//functions in RecordPrinter
void printRecordToFile();
void printRecordToSystem();

//functions in Sorter
void sortRecord(int type, int direction);

#endif