#include "my_memmove.h"

#include <stdio.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    char temp[32767];

    const char *p = src;

    for (size_t i = 0; i < n; i++)
    {
        temp[i] = *p;
        p++;
    }

    char *p2 = dest;
    for (size_t i = 0; i < n; i++)
    {
        *p2 = temp[i];
        p2++;
    }
    return dest;
}
