#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int a[SIZE];
void insert()
{   
    int location,element,i;
    printf("\nEnter location and element: ");
    scanf("%d%d",&location,&element);
    
    for(i=SIZE-1;i!=location-1;i--){ // i >= location - 1 
        a[i] = a[i-1];
    }     
    a[location-1] = element;

}
void deleteElement()
{
}

void display()
{
    int i;
    for(i=0;i<SIZE;i++){
        printf(" %d ",a[i]);
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

        default:
            printf("\nInvalid Choice Please Try Again!!!!");
            break;
        }
    }
    return 0;
}