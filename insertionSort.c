#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
// int a[] = {1,6,4,9,7};

// int a[] = {5, 1, 10, -2, 6}; //-2 1 10 5 6
//  int a[] = {5,4,3,2,1};//1 4 3 2 5
int a[] = {5, 1, 10, -2, 6, 88, 9, 74, 52, 63};
void display()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d ", a[i]);
    }
}
void sort() // n*n n2
{
    int j, tmp, i; // 5 4 3 2 1 / O(n2)  4
    int x;

    //
    //
    for (i = 1; i < SIZE; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (tmp < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = tmp;

        printf("\nAfter Pass %d", i + 1);
        for (x = 0; x < SIZE; x++)
        {
            printf(" %d ", a[x]);
        }
    }
}

int main()
{
    sort();

    return 0;
}