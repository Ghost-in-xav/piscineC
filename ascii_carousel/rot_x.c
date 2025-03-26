

#include <stdio.h>

void rot_x(char *s, int x)
{
    if (s == NULL)
        return;

    x = (x < 0) ? ((26 + x) % 26) : x;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && 'Z' >= s[i])
            s[i] = (((s[i] - 'A') + x) % 26) + 'A';
        ;

        if (s[i] >= 'a' && 'z' >= s[i])
            s[i] = (((s[i] - 'a') + x) % 26) + 'a';
    }
}
/*
int main(void)
{
  char in[] = "bcd";
  printf("In: %s\n", in);
  rot_x(in, -1);
  printf("Out: %s\n", in);
  return 0;
}

*/
