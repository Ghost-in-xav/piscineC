#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    unsigned long x = 1;
    unsigned long y = 1;
    unsigned long z = 1;

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    for (unsigned long i = 2; i < n; i++)
    {
        x = y;
        y = z;
        z = x + y;
    }
    return z;
}
