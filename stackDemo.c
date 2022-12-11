#include <stdio.h>
#include<stdlib.h> 

#define S 5


int stack[S];
int top = -1; // empty

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == S - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push()
{
    int num;

    if (isFull() == 1)
    {
        printf("\nStack Overflow....");
    }
    else
    {
        printf("\nEnter number");
        scanf("%d", &num);
        top++;
        stack[top] = num;
    }
}
void pop()
{
    if (isEmpty() == 1)
    {
        printf("\nStack UnderFlow..");
    }
    else
    {
        printf("\n%d poped ", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
}
void peek()
{
    if (isEmpty() == 1)
    {
        printf("\nStack underflow..");
    }
    else
    {
        printf("\n%d", stack[top]);
    }
}

void peep(){
    int location,ind;
    printf("\nEnter location");
    scanf("%d",&location);
    ind = top-location+1;
    printf("\n %d ",stack[ind]);


}

void exhange(){

}
int main()
{
    int choice;

    while (1)
    {
        printf("\n0 For EXIT\n1 For Push\n2 For Pop\n3 for Peek\n4 For Display\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;

        default:
            printf("\nInvalid Choice Try Again!!!");
            break;
        }
    }
    return 0;
}
