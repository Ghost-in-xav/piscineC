#include <stdio.h>

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

/*#include "my_pow.h"
int main(void)
{
    int a = 5;
    int b = 3;
    printf("%d\n", my_pow(a, b));
    return 0;
}
*/
