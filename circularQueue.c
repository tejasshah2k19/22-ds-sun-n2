#include <stdio.h>
#include <stdlib.h>

#define S 5

int q[S];

int f = -1;
int r = -1;

int isFull()
{
    if (r == S - 1 && f == 0)
    {
        return 1;
    }
    else if (r == f - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    return f == -1;
}

void insert()
{
    int num;

    if (isFull())
    {
        printf("\nQueue is Full");
    }
    else
    {
        printf("\nEnter number");
        scanf("%d", &num); //  70 

        if (r == S - 1)
        {
            r = 0;
            q[r] = num;
        }
        else
        {
            r++;
            q[r] = num;
            if (f == -1)
                f++;
        }
    }
}

void remove1()
{
    if (isEmpty())
    {
        printf("\nQ is E");
    }
    else
    {
        printf("%d is Removed ", q[f]);

        if (f == r)
        {
            f = -1;
            r = -1;
        }else if( f == S - 1){
            f=0;
        }
        else
        {
            f++;
        }
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is Empty");
    }
    else if( f > r ){
        for(i=f;i<=S-1;i++){
            printf("  %d", q[i]);
        }
        for(i=0;i<=r;i++){
            printf("  %d", q[i]);
        }
    }
    else
    {
        for (i = f; i <= r; i++)
        {
            printf("  %d", q[i]);
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n0 For EXIT\n1 For insert\n2 For delete\n3 For Display\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            insert();
            break;
        case 2:
            remove1();
            break;
        case 3:
            display();
            break;

        default:
            printf("\nInvalid Choice Try Again!!!");
            break;
        }
    }
    return 0;
}
