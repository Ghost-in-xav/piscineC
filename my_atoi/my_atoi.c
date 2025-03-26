#include "my_atoi.h"

#include <stdio.h>

int my_atoi(const char *str)
{
    int signe = 0;
    int moins = 0;
    int allowed = 0;
    int digit = 0;

    const char *p = str;
    while (*p != '\0')
    {
        while (*p == ' ' && signe == 0 && allowed == 0)
            p++;

        if ((*p == '-' || *p == '+') && signe == 0 && allowed == 0)
        {
            if (*p == '-')
                moins = 1;
            signe = 1;
            allowed = 1;
            p++;
        }
        while (*p >= 48 && *p <= 57)
        {
            digit *= 10;
            digit += *p - 48;
            p++;
        }
        if (*p != '\0' && digit != 0)
            return 0;
        if (*p != '\0')
            return 0;
    }
    return (moins == 1) ? -digit : digit;
}
