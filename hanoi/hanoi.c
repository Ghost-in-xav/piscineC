#include <stdio.h>

void chapeau(unsigned n, char A, char B, char C)
{
    if (n >= 1)
    {
        chapeau(n - 1, A, C, B);
        printf("%c->%c\n", A, C);
        chapeau(n - 1, B, A, C);
    }
}

void hanoi(unsigned n)
{
    char A = '1';
    char B = '2';
    char C = '3';
    chapeau(n, A, B, C);
}
