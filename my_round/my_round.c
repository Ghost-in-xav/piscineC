#include <stdio.h>

int my_round(float n)
{
    if (n > 0)
        return (n + 0.5);
    return (n - 0.5);
}

/*
int main(void)
{
  printf("%d\n",my_round(42.50));
  printf("%d\n",my_round(-42.50));
  return 0;
}
*/
