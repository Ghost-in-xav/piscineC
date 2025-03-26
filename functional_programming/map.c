#include <stddef.h>
#include <stdio.h>

#include "functional_programming.h"

void map(int *array, size_t len, void (*func)(int *))
{
    int *res = array;
    for (size_t i = 0; i < len; i++)
    {
        func(res);
        res++;
    }
}
