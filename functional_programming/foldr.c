#include <stddef.h>
#include <stdio.h>

#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int *p = array;
    for (size_t i = 0; i < len - 1; i++)
        p++;
    int res = 0;
    for (size_t i = len; i > 0; i--)
    {
        res = func(*p, res);
        p--;
    }
    return res;
}
