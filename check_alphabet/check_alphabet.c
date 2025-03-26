#include "check_alphabet.h"

#include <stddef.h>
#include <stdio.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL || *alphabet == '\0')
        return 1;

    const char *p = str;
    while (*p != '\0')
    {
        if (*p == *alphabet)
        {
            alphabet++;
            return check_alphabet(str, alphabet);
        }

        p++;
    }
    return 0;
}
