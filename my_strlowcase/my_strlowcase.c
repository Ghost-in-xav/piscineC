#include "my_strlowcase.h"

#include <stdio.h>

void my_strlowcase(char *str)
{
    char *p = str;
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            *p += 32;
        p++;
    }
}
