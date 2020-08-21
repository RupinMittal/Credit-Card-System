#ifndef RECORDHEADER_H  //guard against infinite loop of includes
#define RECORDHEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generateRecord();
int randomAmount(int lower, int higher);
void randomLocation(char *location);
void randomDate(char *date);

#endif