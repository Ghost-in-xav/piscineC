#include "my_strcmp.h"

#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return (*s1 > *s2) ? 1 : -1;
        s1++;
        s2++;
    }

    if (*s1 == '\0' || *s2 == '\0')
    {
        if (*s1 == '\0' && *s2 != '\0')
            return -1;
        if (*s1 != '\0' && *s2 == '\0')
            return 1;
    }

    return 0;
}
