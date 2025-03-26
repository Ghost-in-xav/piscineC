#include <stdio.h>
// #include "count_words.h"

int count_words(const char *file_in)
{
    int res = 0;

    if (file_in == NULL)
        return -1;

    // ouverteure file read only
    FILE *ptr = fopen(file_in, "r");

    if (ptr == NULL)
        return -1;

    int word = 0;
    char ch = '\0';
    // parcours du fichier ligne par ligne
    while (ch != EOF)
    {
        ch = fgetc(ptr);
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            res += (word == 1) ? 1 : 0;
            word = 0;
        }
        else if (ch != EOF)
            word = 1;
    }
    fclose(ptr);
    return (word == 1) ? res + 1 : res;
}
