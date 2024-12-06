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

void printResult(int* results, int size)
{
    printf("Результирующая строка: ");
    for (int i = 0; i < size - 1; ++i)
    {
        printf("%c", results[i]);
    }
}
