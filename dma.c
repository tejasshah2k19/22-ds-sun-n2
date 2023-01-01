#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20];
    int m, s, e;
};

int main()
{
    struct student *s; // null //name m s e
    int *a, i;
    int *x;
    a = (int *)calloc(5, sizeof(int));
    s = (struct student *)malloc(sizeof(struct student));

    x = (int *)malloc(sizeof(int) * 5);

    // s.name
    // s->name
    // s->m
    for (i = 0; i < 5; i++)
    {
        printf("\nEnter value");
        scanf("%d", &a[i]);
    }
    printf("\nElement in array");
    for (i = 0; i < 5; i++)
    {
        printf("\n%d", a[i]);
    }

    free(a);
    free(s);
    return 0;
}
//   int *a;

//     a = (int *)calloc(5, 4); // 20    a[0] a[1] a[2] a+0 a+1 a+2
//     int *p = (int *)malloc(sizeof(int));
// void* calloc(int count,int size)

// int a;
// int *p;
//  p = &a;

// float f;
// float  *p;
// p = &f;

// void *p;
// int a;
//  p =(int*) &a;