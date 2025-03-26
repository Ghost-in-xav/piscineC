#include <stdio.h>

int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    if (n < 10)
        return 1;
    int travel = n;
    int compare = 0;
    while (travel >= 10)
    {
        compare += (travel % 10);
        compare *= 10;
        travel = travel / 10;
    }
    compare += travel;

    return (compare == n) ? 1 : 0;
}
/*
int main(void)
{
  printf("%d\n",int_palindrome(12344321));
  return 0;
}

*/
