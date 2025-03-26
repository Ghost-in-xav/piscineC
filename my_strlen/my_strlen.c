#include "my_strlen.h"

size_t my_strlen(const char *s)
{
    size_t res = 0;
    while (*s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

/*
int main(void)
{
  const char *s = "jesuiscon";
  printf("%ld\n",my_strlen(s));
  return 0;
}

 */
