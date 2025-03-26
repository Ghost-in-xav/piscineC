#include "my_strspn.h"

#include <stddef.h>
#include <stdio.h>

size_t check_chapeau(const char *str, const char *alphabet)
{
    size_t res = 0;
    const char *p = str;
    while (*p != '\0')
    {
        size_t before = res;
        const char *p2 = alphabet;
        while (*p2 != '\0')
        {
            res += (*p2 == *p) ? 1 : 0;
            p2++;
        }
        p++;
        if (res == before)
            return res;
    }
    return res;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t res = check_chapeau(s, accept);
    return res;
}
