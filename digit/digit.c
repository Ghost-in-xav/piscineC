#include <stdio.h>

unsigned int digit(int n, int k)
{
    int res = n;
    if (n <= 0 || k <= 0)
        return 0;
    for (int i = 0; i < k - 1; i++)
        res = res / 10;
    return res % 10;
}
