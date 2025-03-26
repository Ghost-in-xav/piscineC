#include "my_itoa.h"

#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int value, char *s)
{
    char *p = s;
    char *p1 = s;
    int signe = 0;
    if (value < 0)
    {
        value = -value;
        signe = 1;
    }

    else if (value == 0)
    {
        *p = '0';
        p++;
        *p = '\0';
        return s;
    }
    while (value > 0)
    {
        if (value % 10 == 0)
            *p = '0';
        else
            *p = (value % 10) + 48;
        p++;
        value /= 10;
    }
    if (signe == 1)
    {
        *p = '-';
        p++;
    }
    *p = '\0';
    p--;
    while (p1 <= p)
    {
        char temp = *p;
        *p = *p1;
        *p1 = temp;
        p--;
        p1++;
    }
    return s;
}
