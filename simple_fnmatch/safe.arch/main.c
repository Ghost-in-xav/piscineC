#include <fnmatch.h>
#include <stdio.h>

#include "simple_fnmatch.h"
#define FNM_NOMATCH 1

int main(void)
{
    char path1[] = "*?*?*?*?\\*?";
    char str1[] = "toto?";
    int actual1 = simple_fnmatch(path1, str1);
    int expected1 = fnmatch(path1, str1, 0);
    printf("actual = %d\n", actual1);
    printf("expected = %d\n", expected1);
    return 0;
}
