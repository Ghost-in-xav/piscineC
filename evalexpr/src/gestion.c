#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigpointh.h"

char *gestion(char *input)
{
    char *temp1 = remove_spaces(input);
    char *temp2 = unary_op(temp1);
    char *temp3 = remove_spaces(temp2);
    char *temp4 = unary_conflict(temp3);
    char *temp5 = remove_spaces(temp4);
    input = temp5;
    free(temp1);
    free(temp4);
    return input;
}

char *remove_spaces(char *input)
{
    int index = 0;
    char *res = malloc(200 * sizeof(char));
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ')
        {
            res[index] = input[i];
            index++;
        }
    }
    res[index] = '\0';
    res = realloc(res, (index + 1) * sizeof(char));
    return res;
}

char *unary_conflict(char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '+')
            input[i] = (input[i + 1] == '-') ? ' ' : input[i];
        if (input[i] == '-')
            input[i + 1] = (input[i + 1] == '+') ? '-' : input[i + 1];
        if (input[i] == '+')
            input[i] = (input[i + 1] == '+') ? ' ' : input[i];
    }
    return input;
}

char *unary_op(char *input)
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '-')
        {
            count++;
            if (count == 2)
            {
                input[i - 1] = '+';
                input[i] = ' ';
                count = 0;
                i = 0;
            }
            if (input[i + 1] == '+')
            {
                input[i + 1] = ' ';
                i--;
            }
        }
        else
        {
            count = 0;
            if (is_op(input[i]) == 1 && input[i + 1] == '+')
            {
                input[i + 1] = ' ';
            }
        }
    }
    return input;
}
