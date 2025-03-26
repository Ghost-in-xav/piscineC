#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigpointh.h"

int is_op(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return 1;
    return 0;
}

void check_valid(char *input)
{
    int i = 0;
    if (input[i] == '\0')
        exit(0);
    while (input[i] != '\0')
    {
        if (is_op(input[i]) == 0 && isdigit(input[i]) == 0 && input[i] != '('
            && input[i] != ')' && input[i] != '\n')
            exit(1);
        if (is_op(input[i]) == 1 && is_op(input[i + 1]) == 1)
        {
            if (input[i + 1] == '-')
                return;
            else
                exit(2);
        }
        if (is_op(input[0]) == 1 && isdigit(input[1]) == 0)
            exit(2);
        if ((input[i] == '/' && input[i + 1] == '0')
            || (input[i] == '%' && input[i + 1] == '0'))
            exit(3);
        if (input[i] == '^' && input[i + 1] == '-')
            exit(3);
        i++;
    }
    if (Isequilibrer(input) == -1)
        exit(2);
    if (is_op(input[i - 1]) == 1)
        exit(2);
}

void recuperation_operand_operator(char *input)
{
    int bool = 0;
    int acc = 0;
    int operand = 0;
    int operator= 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' || input[i] == '\n')
        {
            if (bool == 1)
                operand++;
            acc = 0;
            bool = 0;
            continue;
        }
        if (is_op(input[i]) == 1)
            operator++;
        else
        {
            if (bool == 1)
                acc = acc * 10 + (input[i] - '0');
            else
            {
                acc += (input[i] - '0');
                bool = 1;
            }
        }
    }
    if (bool == 1)
        operand++;

    if (operator== 1)
        if (operand != 2)
            exit(2);

    if (operator> 1)
        if (operand != operator+ 1)
            exit(2);
}

void check_valid_rpn(char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(' || input[i] == ')')
            exit(1);
        if (is_op(input[i]) == 0 && isdigit(input[i]) == 0 && input[i] != ' '
            && input[i] != '\0')
            exit(1);
    }
    recuperation_operand_operator(input);
}
