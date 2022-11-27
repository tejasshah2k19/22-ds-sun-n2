#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
// int a[] = {1,6,4,9,7};

int a[] = {5,4,3,2,1};
  
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
    int isSwap = 1;
    //
    //
    for (i = 0; i < SIZE && isSwap == 1; i++) // 5
    {   
        isSwap = 0;
        printf("\nPass %d started:- ",i+1);
        for (j = 0; j < SIZE - 1-i; j++) // 5  4
        {
            printf("\nComparing %d and %d",a[j],a[j+1]);
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                isSwap = 1;
            }
        }
        printf("\nAfter Pass %d",i+1);
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