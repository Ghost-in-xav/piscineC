#include "bubble_sort.h"

void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void bubble_sort(int array[], size_t size)
{
    while (size >= 1)
    {
        size_t new_size = 0;
        for (size_t i = 1; i <= size - 1; i++)
        {
            if (array[i - 1] > array[i])
            {
                swap(array, i - 1, i);
                new_size = i;
            }
        }
        size = new_size;
    }
}
/*
#include <stdio.h>
int main(void)
{
  int array[5]={6,1,8,5,4};
  for(size_t i = 0;i<5;i++)
    printf("%d",array[i]);
  printf("\n");
  bubble_sort(array,5);
  for(size_t i = 0;i<5;i++)
    printf("%d",array[i]);
   printf("\n");
  return 0;
}
*/
