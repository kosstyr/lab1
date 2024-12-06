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

int main(int argc, char **argv) {
    if ((argc % 3) != 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int results[argc / 3];
    int key = atoi(argv[argc - 1]);
    for (int i = 1; argc; i += 3)
    {
        if (i == argc - 2)
        {
            break;
        }
        //printf("%s %s %s\n", argv[i], argv[i + 1], argv[i + 2]);
        int result = calculate(argv[i], argv[i + 1], argv[i + 2]);
        results[i / 3] = result - key;
        printf("Ответ №%d: %d\n", (i / 3) + 1, result);
    }

    printf("Результирующая строка: ");
    for (int i = 0; i < (argc / 3); ++i)
    {
        printf("%c", results[i]);
    }
    printf("\n");

    return 0;
}

