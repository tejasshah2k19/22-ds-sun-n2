#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
#define SIZE2 7

// int a[] = {1,6,4,9,7};

int a[] = {10, 20, 30, 40};
int b[] = {1, 5, 7, 19, 22, 33, 67};
int c[SIZE + SIZE2];
void display()
{
    int i;
    for (i = 0; i < SIZE + SIZE2; i++)
    {
        printf(" %d ", c[i]);
    }
}
void sort() // n*n n2
{
    int i = 0, j = 0, k = 0;

    while (i < SIZE && j < SIZE2)
    {
        if (a[i] > b[j])
        {
            c[k++] = b[j++];
        }
        else
        {
            c[k++] = a[i++];
        }
    }
    if (i < SIZE)
    {
        while (i < SIZE)
        {
            c[k++] = a[i++];
        }
    }
    else if (j < SIZE2)
    {

        while (j < SIZE2)
        {
            c[k++] = b[j++];
        }
    }
}
int main()
{
    sort();
    display();

    return 0;
}