
#include "element_count.h"

size_t element_count(int *begin, int *end)
{
    size_t res = 0;
    while (begin++ != end)
    {
        res++;
    }
    return res;
}
/*
  #include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int *tab=calloc(10,sizeof(char));
  int *end =tab;
  end+=0;
  size_t res = element_count(tab,end);
  printf("nbre_element = %lu\n",res);
  return res;
}
*/
