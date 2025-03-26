#include <stdio.h>

int main(void)
{
    const char *alpha = "a b c d e f g h i j k l m n o p q r s t u v w x y z\n";
    for (int i = 0; i < 52; i++)
        putchar(alpha[i]);
    return 0;
}
