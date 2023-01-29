#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *last = NULL;

struct node *createNode(int num)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));//35
    tmp->data = num;
    tmp->next = NULL;
    return tmp;
}

void insertLast(int num)
{
    struct node *tmp;

    if (head == NULL)
    {
        head = createNode(num);
        last = head;
    }
    else
    {
        tmp = createNode(num);
        last->next = tmp;
        last = tmp;
    }
}

void insertBeg(int num)
{
    struct node *tmp;

    if (head == NULL)
    {
        insertLast(num);
    }
    else
    {
        tmp = createNode(num);
        tmp->next = head;
        head = tmp;
    }
}

void insertAny(int source,int num){
    struct node *p,*q,*tmp;
    p = head;

    while(p!=NULL){
        if(p->data == source){
            break;
        }
        p =p->next;
    }
    if( p  == NULL){
        printf("\nInvalid Source");
    }else{ 
        q = p->next; 
        tmp = createNode(num);
        p->next = tmp;
        tmp->next = q; 
    }
    
}

void display()
{
    struct node *p = head;
    printf("\nContent of the linked list\n");
    while (p != NULL)
    { // p->next != NULL
        printf(" %d ", p->data);
        p = p->next;
    }
}

void deleteBeg(){
    struct node *p = head; 
    head = head->next; 
    free(p);
}

void deleteLast()
{
    struct node *p;
    p = head;
    while (p->next != last)
    {
        p = p->next;
    }

    p->next = NULL;
    free(last);
    last = p;
}

void deleteAny(int num){
 struct node *p,*q,*r;
    p = head;

    while(p!=NULL){
        if(p->data == num){
            break;
        }
        p =p->next;
    }
    if( p  == NULL){
        printf("\nInvalid Number");
    }else{ 
        q = head; 
        while(q->next != p){
            q = q->next; 
        }
        r= p->next; 
        q->next = r;
        free(p);
    }
}
int main()
{

    createNode(10); // head
    createNode(20); //
    createNode(30);
    createNode(40);
    display();
    createNode(50);
    createNode(60);
    display();

    return 0;
}