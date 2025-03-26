#include "my_strstr.h"

#include <stdio.h>

int my_len(const char *test)
{
    int res = 0;
    const char *p = test;
    while (*p != '\0')
    {
        p++;
        res++;
    }
    return res;
}
int my_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
        return 0;
    if (my_len(needle) > my_len(haystack))
        return -1;

    const char *p = haystack;
    int index = 0;
    int count = 0;
    // Tant que tout haystack n est pas parcouru
    while (*p != '\0')
    {
        // pointeur sur needle
        const char *p1 = needle;
        const char *beforep = p;
        while (*p != '\0' && *p1 != '\0' && *p == *p1)
        {
            p1++;
            p++;
            count++;
        }
        // sorti de la boucle donc soit un des deux str est finis soit plus
        // egaux
        if (*p1 == '\0' && count > 0)
            return index;
        if (*p1 == '\0')
            return -1;
        if (*p == '\0')
            return -1;
        // si sorti car juste plus egaux alors on remet p au depart de haystack
        index++;
        p = beforep;
        // et on l'incremente pour le faire passer apres le premier egal
        p++;
    }
    return (count == 0) ? -1 : index;
}
