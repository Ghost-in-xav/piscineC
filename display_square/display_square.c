#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;
    int lar = (width % 2 == 0) ? width + 1 : width;
    int lig = (lar + 1) / 2;

    for (int i = 0; i < lig; i++)
    {
        for (int j = 0; j < lar; j++)
        {
            if (i == 0 || i == lig - 1)
                putchar('*');
            else if (j == 0 || j == lar - 1)
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
/*
int main(void)
{
  display_square(11);
  return 0;
}

*/
