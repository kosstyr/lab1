#include "lab1.h"

//argc (argument count) - кол-во аргументов
//argv (argument values) - массив со значениями аргументов
//первый аргумент (argv[0]) - всегда название исполняемого файла, поэтому почти везде начинаем со второго элемента
//последний аргумент - argv[argc - 1]
int main(int argc, char **argv) {
    int inputValidationResultCode = validateInput(argc, argv);
    if (inputValidationResultCode != 0)
    {
        return inputValidationResultCode;
    }

    //Создаём массив размером кол-во аргументов / 3, чтобы хранить результаты
    //каждой комбинации число операция число
    int results[argc / 3];
    int key = atoi(argv[argc - 1]);
    //начинем проходиться по массиву
    //пропускаем нулевой аргумент (название исполняемого файла)
    //идём с шагом 3 (первое число, операция, второе число, _следующее первое число_...)
    for (int i = 1; i < argc - 2; i += 3)
    {
        //printf("%s %s %s\n", argv[i], argv[i + 1], argv[i + 2]);
        int result = calculate(argv[i], argv[i + 1], argv[i + 2]);
        printf("Ответ №%d: %d\n", (i / 3) + 1, result);
        results[i / 3] = result - key;
    }
    printResult(results, argc / 3);

    printf("\n");

    return 0;
}

int validateInput(int argc, char** argv)
{
    int code = 0;
    if (argc < 6)
    {
        printf("Не пройдена проверка: должно быть минимум 5 аргументов.\n");
        code = 1;
    }
    else if ((argc % 3) != 0)
    {
        printf("Не пройдена проверка: кол-во аргументов должно быть кратно 3.\n");
        code = 1;
    }
    else if (!isNumber(argv[argc - 1]))
    {
        printf("Не пройдена проверка: последний аргумент должен быть числом.\n");
        code = 1;
    }
    else if (strcmp(argv[argc - 2], "-k") != 0)
    {
        printf("Не пройдена проверка: предпоследний аргумент должен быть -k.\n");
        code = 1;
    }

    if (code == 0)
    {
        for (int i = 1; i < argc - 2; i += 3)
        {
            //strcmp - функция сравнения строк, если строки равны, возвращает 0
            if ((strcmp(argv[i + 1], "%") == 0) && (strcmp(argv[i + 2], "0") == 0))
            {
                printf("Не пройдена проверка: деление на 0.\n");
                code = 1;
                break;
            }
            else if (!isNumber(argv[i]) || !isNumber(argv[i + 2]) || !isCharacterInString(argv[i + 1][0], "+-*%"))
            {
                printf("Не пройдена проверка: первый и третий аргумент в парах - числа, средний - поддерживаемая операция.\n");
                code = 1;
                break;
            }
        }
    }

    if (code != 0)
    {
        printf("Ошибка вводных данных.\n");
    }
    return code;
}

int isCharacterInString(char operation, char* potentialOperations)
{
    //strchr - функция проверки наличия символа в строке
    //если возвращает NULL, значит, символа в строке нет
    if (strchr(potentialOperations, operation) != NULL)
    {
        return 1;
    }
    return 0;
}

int isNumber(char* potentialNumber)
{
    if (*potentialNumber == '-')
    {
        potentialNumber++;
    }

    //пока указатель имеет значение
    while (*potentialNumber) {
        if (!isdigit(*potentialNumber)) {
            return 0;
        }
        potentialNumber++;
    }
    return 1;
}

void printResult(int* results, int size)
{
    printf("Результирующая строка: ");
    for (int i = 0; i < size - 1; ++i)
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
