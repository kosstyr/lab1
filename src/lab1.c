#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(char* aChar, char* operation, char* bChar)
{
    int a = atoi(aChar);
    int b = atoi(bChar);

    if (strcmp(operation, "+") == 0)
    {
        return a + b;
    }
    return -1;
}

int main(int argc, char **argv) {
    if ((argc % 3) != 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 1; argc; i += 3)
    {
        if (i == argc - 2)
        {
            break;
        }
        //printf("%s %s %s\n", argv[i], argv[i + 1], argv[i + 2]);
        printf("%d\n", calculate(argv[i], argv[i + 1], argv[i + 2]));
    }
    return 0;
}

