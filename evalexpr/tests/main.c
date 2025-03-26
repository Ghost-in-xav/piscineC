#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../src/bigpointh.h"

int main(int argc, char *argv[])
{
    if (argc < 0)
        return 3;
    char buffer[5000];

    if (argc == 2)
    {
        if (strcmp(argv[1], "-rpn") == 0)
        {
            char *input = fgets(buffer, 5000, stdin);
            if (input == NULL)
                return 0;
            check_valid_rpn(input);
            int res = lapolonaisedesesmorts(input);
            fprintf(stdout, "%d\n", res);
            return 0;
        }
        else
            exit(4);
    }
    else
    {
        if (argc > 2)
            return 4;
        char *input = fgets(buffer, 5000, stdin);
        if (input == NULL)
            return 0;
        input = gestion(input);
        check_valid(input);
        char *convert = convertir(input);
        // printf("apres conversion : %s\n",convert);
        int res = lapolonaisedesesmorts(convert);
        fprintf(stdout, "%d\n", res);
        free(input);
        free(convert);
        return 0;
    }
    return 4;
}
