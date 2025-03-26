#include "my_strtok_r.h"

#include <stdio.h>

static int is_delimiteur(char c, const char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++)
    {
        if (delim[i] == c)
            return 1;
    }
    return 0;
}

static int len(char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++)
        res++;
    return res;
}

static char *_round(char *str, const char *delim, char **saveptr)
{
    while (is_delimiteur(*str, delim) == 1)
        str++;
    if (*str == '\0')
        return NULL;
    char *res = str;
    int taille_str = 0;

    while (res != NULL && *res != '\0')
    {
        if (is_delimiteur(*res, delim) == 1 && taille_str > 0)
        {
            *res = '\0';
            res++;
            while (is_delimiteur(*res, delim) == 1)
                res++;
            *saveptr = res;
            return str;
        }
        else
        {
            res++;
            taille_str++;
        }
    }
    if (taille_str == len(str))
    {
        *saveptr = NULL;
        return str;
    }
    if (*res == '\0' && **saveptr != '\0')
    {
        res = *saveptr;
        *saveptr = NULL;
        return res;
    }
    return str;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (saveptr == NULL)
        return NULL;

    if (delim == NULL)
        return *saveptr;

    if (str != NULL)
    {
        if (*str == '\0')
        {
            saveptr = NULL;
            return NULL;
        }
        if (*delim == '\0')
        {
            *saveptr = NULL;
            return str;
        }
        return _round(str, delim, saveptr);
    }

    if (str == NULL && *saveptr != NULL)
    {
        str = *saveptr;
        if (**saveptr == '\0')
            return NULL;
        return _round(str, delim, saveptr);
    }
    return NULL;
}
