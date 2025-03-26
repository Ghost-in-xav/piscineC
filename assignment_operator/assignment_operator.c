#include <stdio.h>
/*#include "assignment_operator.h"*/

/*
int main(void)
{
  int test1=-48;
  int test2=8;
  int *a=&test1;
  int *b=&test2;

  minus_equal(a,b);
  printf("%d\n",*a);
  return 0;
}
*/

void plus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a = (*a + *b);
}

void minus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a = (*a - *b);
}

void mult_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a = (*a * *b);
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return 0;
    int remainder = *a % *b;
    *a = (*a / *b);
    return remainder;
}
