#include <stddef.h>
#include <stdio.h>

size_t len(const char *source)
{
    size_t len = 0;
    while (source[len] != '\0')
        len++;
    return len;
}

char *my_strcpy(char *dest, const char *source)
{
    size_t taille = len(source);
    for (size_t i = 0; i < taille; i++)
        dest[i] = source[i];
    dest[taille] = '\0';
    return dest;
}
