#include <stdio.h>

int int_sqrt(int n)
{
    if (n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;
    int debut = 0;
    int fin = n;
    int mid = 0;
    int res = 0;
    while (debut <= fin)
    {
        mid = (debut + fin) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid < n)
        {
            debut = mid + 1;
            res = mid;
        }
        else
            fin = mid - 1;
    }
    return res;
}
/*
int main(void)
{
  printf("%d\n",int_sqrt(25));
    return 0;
}
*/
