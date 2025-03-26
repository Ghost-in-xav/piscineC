#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;

    for (unsigned ligne = 0; ligne < n; ligne++)
    {
        for (unsigned space_before = 0; space_before < n - ligne - 1;
             space_before++)
            putchar(' ');
        for (unsigned inside = n - ligne; inside < n + ligne; inside++)
            putchar('*');
        putchar('*');
        putchar('\n');
    }
    for (unsigned ligne_trunk = 0; ligne_trunk < (n / 2); ligne_trunk++)
    {
        for (unsigned before_trunk = 0; before_trunk < n - 1; before_trunk++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }

    return 0;
}
/*
int main(void)
{
  return pine(5);
}
*/
