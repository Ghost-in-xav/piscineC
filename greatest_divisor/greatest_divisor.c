#include <stdio.h>

unsigned int greatest_divisor(unsigned int n)
{
    if (n == 1)
        return 1;
    for (unsigned int i = n - 1; i > 0; i--)
        if (n % i == 0)
            return i;
    return 69;
}
