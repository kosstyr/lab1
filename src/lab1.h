#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printResult(int* results, int size);

int calculate(char* aChar, char* operation, char* bChar);

int validateInput(int argc, char** argv);

int isNumber(char* potentialNumber);
