#include "my_atoi_base.h"

#include <stddef.h>
#include <stdio.h>

int my_pow(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
        return my_pow(a * a, b / 2);
    return a * my_pow(a * a, (b - 1) / 2);
}

int tail(const char *str)
{
    int taille = 0;
    for (int i = 0; str[i] != '\0'; i++)
        taille += (str[i] == ' ' || str[i] == '+' || str[i] == '-') ? 0 : 1;
    return taille;
}

int basos(const char *base)
{
    int num_base = 0;
    for (int i = 0; base[i] != '\0'; i++)
        num_base += 1;
    return num_base;
}

int counter(const char *base, const char *p, int num_base)
{
    int count = 0;
    for (int i = 0; base[i] != *p && i < num_base; i++)
        count++;
    return count;
}

int my_atoi_base(const char *str, const char *base)
{
    int signe = 0;
    int moins = 0;
    int digit = 0;
    int num_base = basos(base);
    int taille = tail(str);
    const char *p = str;
    while (*p != '\0')
    {
        while (*p == ' ' && signe == 0)
            p++;

        if ((*p == '-' || *p == '+') && signe == 0)
        {
            if (*p == '-')
                moins = 1;
            signe = 1;
            p++;
        }
        int puissance = taille - 1;
        while (*p != '\0')
        {
            if (*p == '+' || *p == '-' || *p == ' ')
                return 0;
            int count = counter(base, p, num_base);
            int seen = (base[count] == *p) ? 1 : 0;
            if (seen == 0)
                return 0;
            digit += (count * my_pow(num_base, puissance));
            p++;
            puissance--;
        }
        if (*p != '\0' && digit != 0)
            return 0;
        if (*p != '\0')
            return 0;
    }
    return (moins == 1) ? -digit : digit;
}
