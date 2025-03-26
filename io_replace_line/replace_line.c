#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    if (file_in == NULL || file_out == NULL)
        return -1;

    FILE *ptr1 = fopen(file_in, "r");
    FILE *ptr2 = fopen(file_out, "w+");

    if (ptr1 == NULL || ptr2 == NULL)
        return -1;

    char *l1 = NULL;
    size_t len = 0;
    ssize_t read;
    int res = 0;
    int count = 0;

    read = getline(&l1, &len, ptr1);
    while (read != -1)
    {
        if (count == n)
        {
            fputs(content, ptr2);
            res = count;
        }
        else
        {
            fputs(l1, ptr2);
        }
        read = getline(&l1, &len, ptr1);
        count++;
    }

    fclose(ptr1);
    fclose(ptr2);
    free(l1);
    return (res == n) ? 0 : 1;
}
/*
int main(void)
{
  int res = replace_line("test.c", "test2.c","pieton\n",0);
    printf("%d\n", res);
    return 0;
}

*/
