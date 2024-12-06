#include "validate.h"
#include "utils.h"

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
