#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    if (begin == end)
        return begin;

    if (end >= begin)
    {
        int *mid = begin + (end - begin) / 2;
        int curr = *mid;
        if (curr == elt)
            return mid;
        if (curr > elt)
            return binary_search(begin, mid, elt);
        mid++;
        return binary_search(mid, end, elt);
    }
    return begin;
}
/*

int main(void)
{
int a[] = { 0, 1, 4, 5, 9, 10, 18, 22, 42, 51, 69 };
assert(binary_search(a, a + 11, 5) == a + 3);
assert(binary_search(a, a + 11, 0) == a);
assert(binary_search(a, a + 11, -1) == a);
assert(binary_search(a, a + 11, 99) == a + 11);
assert(binary_search(a, a + 11, 68) == a + 10);
assert(binary_search(a, a, 5) == a);
}
*/
