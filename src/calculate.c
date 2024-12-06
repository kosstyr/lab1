#include "calculate.h"

int calculate(char* aChar, char* operation, char* bChar)
{
    int a = atoi(aChar);
    int b = atoi(bChar);

    if (strcmp(operation, "+") == 0)
    {
        return a + b;
    }
    else if (strcmp(operation, "-") == 0)
    {
        return a - b;
    }
    else if (strcmp(operation, "*") == 0)
    {
        return a * b;
    }
    else if (strcmp(operation, "%") == 0)
    {
        return a % b;
    }
    return -1;
}
