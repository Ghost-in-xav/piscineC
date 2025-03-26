#include <stdio.h>
#define FNM_NOMATCH 1
#include "simple_fnmatch.h"

int simple_fnmatch_rec(const char *pattern, const char *string, int i, int j);

int case_ignore(const char *pattern, const char *string, int i, int j)
{
    switch (pattern[i + 1])
    {
    case '*':
        if (pattern[i + 1] == string[j])
            return simple_fnmatch_rec(pattern, string, i + 2, j + 1);
        return 1;
    case '?':
        if (pattern[i + 1] == string[j])
            return simple_fnmatch_rec(pattern, string, i + 1, j);
        return 1;
    case '\\':
        if (pattern[i + 1] == string[j])
            return simple_fnmatch_rec(pattern, string, i + 2, j + 1);
        return 1;
    default:
        return simple_fnmatch_rec(pattern, string, i + 1, j);
    }
    return 1;
}

int case_etoile(const char *pattern, const char *string, int i, int j)
{
    if (pattern[i + 1] == '\0')
        return 0;

    for (int k = j; string[k] != '\0'; k++)
    {
        if (simple_fnmatch_rec(pattern, string, i + 1, k) == 0)
        {
            return 0;
        }
    }
    return simple_fnmatch_rec(pattern, string, i + 1, j);
}

int simple_fnmatch_rec(const char *pattern, const char *string, int i, int j)
{
    if (pattern[i] == '\0' && string[j] == '\0')
        return 0;

    if (pattern[i] == '\0')
        return 1;

    if (pattern[i] == '\\')
    {
        if (string[j] == '\0')
            return 1;
        return case_ignore(pattern, string, i, j);
    }

    if (pattern[i] == string[j])
        return simple_fnmatch_rec(pattern, string, i + 1, j + 1);

    if (pattern[i] == '*')
        return case_etoile(pattern, string, i, j);

    if (pattern[i] == '?')
        return simple_fnmatch_rec(pattern, string, i + 1, j + 1);

    return 1;
}

int simple_fnmatch(const char *pattern, const char *string)
{
    return simple_fnmatch_rec(pattern, string, 0, 0);
}
