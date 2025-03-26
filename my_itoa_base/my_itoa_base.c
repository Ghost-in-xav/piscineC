#include "my_itoa_base.h"

#include <stddef.h>
#include <stdio.h>

char *my_itoa_base(int n, char *s, const char *base)
{
    int taille_base = 0;
    int buffer[32] = { 0 };
    int count = 0;
    char *p = s;
    if (n == 0)
    {
        *p = base[0];
        p++;
        *p = '\0';
        return s;
    }

    for (int i = 0; base[i] != '\0'; i++)
        taille_base++;

    if (taille_base == 10 && n < 0)
    {
        n = -n;
        *p = '-';
        p++;
    }

    while (n > 0)
    {
        buffer[count] = n % taille_base;
        n /= taille_base;
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        *p = (base[buffer[i]]);
        p++;
    }
    *p = '\0';
    return s;
}
