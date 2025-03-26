#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf("%s\n", "Hello World!");
    else
    {
        for (int i = 1; i < argc; i++)
            printf("Hello %s!\n", argv[i]);
    }

    return 0;
}
