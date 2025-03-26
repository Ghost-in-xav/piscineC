#include "my_memcpy.h"

#include <stddef.h>
#include <stdio.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char temp[32767];

    const char *p = source;

    for (size_t i = 0; i < num; i++)
    {
        temp[i] = *p;
        p++;
    }

    char *p2 = dest;
    for (size_t i = 0; i < num; i++)
    {
        *p2 = temp[i];
        p2++;
    }
    return dest;
}
