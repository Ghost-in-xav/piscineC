#include "my_memset.h"

void *my_memset(void *s, int c, size_t n)
{
    char *p = s;
    while (p != NULL && n > 0)
    {
        *p = c;
        p++;
        n--;
    }
    return s;
}

/*
#include <stdio.h>
  #include <stdlib.h>
int main(void)
{
  void *test = calloc(10,sizeof(char));
   char *v =test;
  for(int i=0;i<10;i++)
    {
      printf("%d\n",*v);
      v++;
    }
  printf("\n");
  my_memset(test,'a' ,7);
  char *d =test;
  for(int i=0;i<10;i++)
    {
      printf("%c\n",*d);
      d++;
    }
  return 0;
}

*/
