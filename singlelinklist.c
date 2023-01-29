#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;          // 4
    struct node *next; // 8  s
} *head = NULL, *last = NULL;

void addNode()
{
    int num;
    struct node *tmp;
    printf("\nEnter number");
    scanf("%d", &num); // 10
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        last = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

void display()
{
    struct node *s;
    s = head;
    while (s != NULL)
    {
        printf(" %d ", s->data); // 10 20 30 40 50
        s = s->next;
    }
}

void addNodeBeg()
{
    int num;
    struct node *tmp;
    printf("\nEnter number");
    scanf("%d", &num); // 10
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
        last = head;
    }
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = head;
        head = tmp;
    }
}

void search(int num)
{
    int isFound = 0; // not found
    struct node *s = head;

    while (s != NULL)
    {
        if (s->data == num)
        {
            isFound = 1;
            break;
        }
        s = s->next;
    }
    if (isFound == 0)
    {
        printf("\n%d not found...", num);
    }
    else
    {
        printf("\n%d Found..", num);
    }
}

void deleteLast()
{
    struct node *p = head;
    if (isEmpty())
    {
        printf("\nNo Data Found");
    }
    else
    {

        while (p->next != last && p->next != NULL)
        {
            p = p->next;
        }
        printf("\n%d is deleted...", last->data);

        if (last == head)
        {
            free(p);
            head = NULL;
            last = NULL;
        }
        else
        {
            free(last);
            p->next = NULL;
            last = p;
        }
    }
}

void delBeg()
{
    struct node *p = head;
    if (isEmpty())
    {
        printf("No Data found..");
    }
    else
    {
        if (head->next == NULL)
        {
            head = NULL;
            last = NULL;
        }
        else
        {
            head = head->next;
        }
        free(p);
    }
}

bool isEmpty()s
{
    return head == NULL; // true | false
}

void delAny()
{
    int num;
    struct node *p, *r;
    printf("\nEnter number");
    scanf("%d", &num);

    if (isEmpty())
    {
        printf("\nNo Data Found");
    }
    else
    {
        r = head;
        while (r != NULL)
        {
            if (r->data == num)
            {
                break;
            }
            p = r;
            r = r->next;
        }
        if (r == NULL)
        {
            printf("\n Invalid Data");
        }
        else
        {
            if (r == head)
            {
                delBeg();
            }
            else if (r->next == NULL)
            {
                deleteLast();
            }
            else
            {
                p->next = r->next;
                free(r);
            }
        }
    }
}

int main()
{
    int choice;
    int num;

    while (1)
    {
        printf("\n0 For Exit\n1 For Add\n2 For Display\n3 For insertBeg\n4 For search");
        printf("\n5 For Delete Last\n");
        printf("\nEnter choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNode();
            break;
        case 2:
            display();
            break;
        case 3:
            addNodeBeg();
            break;
        case 4:
            printf("\nEnter num for search");
            scanf("%d", &num);
            search(num);
            break;
        case 5:
            deleteLast();
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}
