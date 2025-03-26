#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bigpointh.h"

//////////////////////////////////////////////////////////////////////////////////////////////POW///////////////////////////////////////////////////////////////////////////////////////////////

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
        return my_pow(a * a, b / 2);
    return a * my_pow(a * a, (b - 1) / 2);
}

//////////////////////////////////////////////////////////////////////////////////////////////PLUS//////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *case_plus(struct stack *res, int first, int deuxieme)
{
    deuxieme = stack_peek(res);
    res = stack_pop(res);
    first = stack_peek(res);
    res = stack_pop(res);
    first = first + deuxieme;
    res = stack_push(res, first);
    return res;
}

/////////////////////////////////////////////////////////////////////////////////////////////MOINS//////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *case_moins(struct stack *res, int first, int deuxieme)
{
    deuxieme = stack_peek(res);
    res = stack_pop(res);
    first = stack_peek(res);
    res = stack_pop(res);
    first = first - deuxieme;
    res = stack_push(res, first);
    return res;
}

/////////////////////////////////////////////////////////////////////////////////////////////MULT///////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *case_mult(struct stack *res, int first, int deuxieme)
{
    deuxieme = stack_peek(res);
    res = stack_pop(res);
    first = stack_peek(res);
    res = stack_pop(res);
    first = first * deuxieme;
    res = stack_push(res, first);
    return res;
}

/////////////////////////////////////////////////////////////////////////////////////////////POW///////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *case_pow(struct stack *res, int first, int deuxieme)
{
    deuxieme = stack_peek(res);
    res = stack_pop(res);
    first = stack_peek(res);
    res = stack_pop(res);
    first = my_pow(first, deuxieme);
    res = stack_push(res, first);
    return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////MOD///////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *case_mod(struct stack *res, int first, int deuxieme)
{
    deuxieme = stack_peek(res);
    res = stack_pop(res);
    first = stack_peek(res);
    res = stack_pop(res);
    if (deuxieme == 0)
        exit(3);
    first = first % deuxieme;
    res = stack_push(res, first);
    return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////DIV///////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *case_div(struct stack *res, int first, int deuxieme)
{
    deuxieme = stack_peek(res);
    res = stack_pop(res);
    first = stack_peek(res);
    res = stack_pop(res);
    if (deuxieme == 0)
        exit(3);
    first = first / deuxieme;
    res = stack_push(res, first);
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////OPERATEUR///////////////////////////////////////////////////////////////////////////////////////////////

static struct stack *ope_case(struct stack *res, char input, int first,
                              int deuxieme)
{
    if (input == '+')
        res = case_plus(res, first, deuxieme);
    else if (input == '-')
        res = case_moins(res, first, deuxieme);
    else if (input == '*')
        res = case_mult(res, first, deuxieme);
    else if (input == '^')
        res = case_pow(res, first, deuxieme);
    else if (input == '%')
        res = case_mod(res, first, deuxieme);
    else if (input == '/')
        res = case_div(res, first, deuxieme);
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////UNAIRE//////////////////////////////////////////////////////////////////////////////////////////////////

static int finaliter(struct stack *res, int bool, int acc)
{
    if (bool == 1)
        res = stack_push(res, acc);

    int end = stack_peek(res);
    res = stack_pop(res);
    res = stack_pop(res);
    return end;
}

////////////////////////////////////////////////////////////////////////////////////////POLONAISE///////////////////////////////////////////////////////////////////////////////////////////////

int lapolonaisedesesmorts(char *input)
{
    int first = 0;
    int deuxieme = 0;
    int bool = 0;
    int acc = 0;

    struct stack *res = NULL;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' || input[i] == '\n')
        {
            if (bool == 1)
                res = stack_push(res, acc);
            acc = 0;
            bool = 0;
            continue;
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '/'
            || input[i] == '^' || input[i] == '*' || input[i] == '%')
        {
            if (stack_len(res) < 2)
                return -666;
            res = ope_case(res, input[i], first, deuxieme);
        }
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
    return finaliter(res, bool, acc);
}

/////////////////////////////////////////////////////////////////////////////////////////END////////////////////////////////////////////////////////////////////////////////////////////////////
