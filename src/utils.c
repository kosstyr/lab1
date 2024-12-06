#include "utils.h"

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
