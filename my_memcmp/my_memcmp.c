#include "my_memcmp.h"

#include <stddef.h>
#include <stdio.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    if (num == 0)
        return 0;
    const char *p1 = s1;
    const char *p2 = s2;
    size_t compteur = 0;
    while (*p1 == *p2 && compteur < num)
    {
        p1++;
        p2++;
        compteur++;
    }

    return (*p1 - *p2);
}
