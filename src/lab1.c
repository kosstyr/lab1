#include "lab1.h"

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
        printf("Ответ №%d: %d\n", (i / 3) + 1, result);
        results[i / 3] = result - key;
    }
    printResult(results, argc / 3);

    printf("\n");

    return 0;
}

void printResult(int* results, int size)
{
    printf("Результирующая строка: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%c", results[i]);
    }
}

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
