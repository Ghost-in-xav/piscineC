#include <stdio.h>

void swap(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    unsigned index = start;
    for (unsigned i = start; i < size; i++)
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    return index;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
        return;
    for (unsigned i = 0; i < size - 1; i++)
        swap(arr, i, array_min(arr, i, size));
}
/*
int main(void)
{
  int array[5]={6,1,8,5,4};
  for(size_t i = 0;i<5;i++)
    printf("%d",array[i]);
  printf("\n");
  selection_sort(array,5);
  for(size_t i = 0;i<5;i++)
    printf("%d",array[i]);
   printf("\n");
  return 0;
}
*/
