#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
// #include "merge_files.h"

int merge_files(const char *file_1, const char *file_2)
{
    if (file_1 == NULL || file_2 == NULL)
        return -1;

    FILE *ptr1 = fopen(file_1, "r+");
    FILE *ptr2 = fopen(file_2, "r+");

    if (ptr1 == NULL || ptr2 == NULL)
        return -1;

    char ch1 = '\0';
    char ch2 = '\0';

    while (ch1 != EOF)
        ch1 = fgetc(ptr1);
    while (ch2 != EOF)
    {
        ch2 = fgetc(ptr2);
        if (ch2 == EOF)
            break;
        fputc(ch2, ptr1);
    }

    fclose(ptr1);
    fclose(ptr2);
    return 0;
}
