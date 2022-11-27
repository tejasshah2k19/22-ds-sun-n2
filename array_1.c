#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int a[SIZE];
void insert()
{
    int location, element, i;
    printf("\nEnter location and element: ");
    scanf("%d%d", &location, &element);
    if (a[location - 1] == 0)
    {
        a[location - 1] = element;
    }
    else
    {
        for (i = SIZE - 1; i != location - 1; i--)
        { // i >= location - 1
            a[i] = a[i - 1];
        }
        a[location - 1] = element;
    }
}
void deleteElement()
{
    int location, element, i;
    printf("\nEnter location and element: ");
    scanf("%d", &location);
    for (i = location - 1; i < SIZE - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[i] = 0;
}

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

    for (i = 0; i < SIZE; i++) // 5
    {
        for (j = 0; j < SIZE - 1; j++) // 5  4
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
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

    int choice;

    while (1)
    { // + - true
        printf("\n0 for Exit\n1 For Insert\n2 For Delete\n3 For Display\nPlease Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            insert();
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            sort();
            break;
        default:
            printf("\nInvalid Choice Please Try Again!!!!");
            break;
        }
    }
    return 0;
}