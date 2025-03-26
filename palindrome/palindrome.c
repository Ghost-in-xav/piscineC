#include "palindrome.h"

#include <stddef.h>

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    const char *end = s;
    while (*end != '\0')
        end++;
    end--;
    while (s <= end)
    {
        while ((*s < '0' || (*s > '9' && *s < 'A') || (*s > 'Z' && *s < 'a')
                || *s > 'z')
               && *s != '\0')
            s++;
        while ((*end < '0' || (*end > '9' && *end < 'A')
                || (*end > 'Z' && *end < 'a') || *end > 'z')
               && end > s)
            end--;

        if (*s != *end)
            return 0;
        s++;
        end--;
    }
    return 1;
}
/*
int main(void)
{
  const char *test1 = "tu l'as trop ete, port-salut.";

  printf(" tu l'as trop ete, port-salut. : %d\n",palindrome(test1));

}

*/
