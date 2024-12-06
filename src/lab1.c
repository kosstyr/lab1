#include <stdio.h>

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
        printf("%s %s %s\n", argv[i], argv[i + 1], argv[i + 2]);
    }
    return 0;
}
