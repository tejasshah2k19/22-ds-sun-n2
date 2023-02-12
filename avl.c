#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    int height;
} *root = NULL;

struct node *createNode(int num)
{
    struct node *tmp;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}
struct node *addNode(struct node *root, int num) // 30,50
{                                                // 50
    if (root == NULL)                            // 30
    {
        root = createNode(num);
        return root;
    }
    else
    {
        if (num > root->data) //
        {                     // 30
            // right
            root->right = addNode(root->right, num);
            // 30->right = addNode(40,50);
            // 40->right = addNode(null,50)
        }
        else
        {
            root->left = addNode(root->left, num);
        }
    }
    root->height = calculateHeight(root) + 1;

    int bf = getBalanceFactor(root); // 50 [-2 ]
    // 0 -1 1

    if (bf > 1)
    {
        // LEFT
        if (num < root->left->data ){
            //left 
            return rightRotate(root);
        }else{
            //right 
        }
    }
    else if (bf < -1)
    {
        // Right
        if (num > root->right->data)
        {
            // Right
            return leftRotate(root);
        }else{
            //Left 
            rightRotate(root->right->left);
            return leftRotate(root);
        }
    }

    return root;
}

struct node *rightRotate(struct node *root){

}
struct node *leftRotate(struct node *root)
{
    struct node *rr = root->right;
    struct node *rrLeft = rr->left;

    root->right = rr->left;
    rr->left = root;

    root->height = calculateHeight(root) + 1;
    rr->height = calculateHeight(rr) + 1;
    return rr;
}
int calculateHeight(struct node *root)
{
    int lch = 0, rch = 0;
    if (root->left != NULL)
    {
        lch = root->left->height;
    }

    if (root->right != NULL)
    {
        rch = root->right->height; // 1
    }

    if (lch > rch)
    {
        return lch;
    }

    else
    {
        return rch;
    }
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return calculateHeight(N->left) - calculateHeight(N->right);
}

void inOrder(struct node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);       //
        printf("%d ", root->data); // 5 20 30 35 40
        inOrder(root->right);      // 30->right 40->right
    }
}

void preOrder(struct node *root)
{

    if (root != NULL)
    {

        printf("%d ", root->data); // 5 20 30 35 40
        preOrder(root->left);      //
        preOrder(root->right);     // 30->right 40->right
    }
}

void postOrder(struct node *root)
{

    if (root != NULL)
    {

        postOrder(root->left);     //
        postOrder(root->right);    // 30->right 40->right
        printf("%d ", root->data); // 5 20 30 35 40
    }
}

struct node *deleteNode(struct node *root, int num)
{ // 50,250
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->data == num)
        {
            // delete

            if (root->left == NULL && root->right == NULL)
            {

                free(root);
                return NULL;
            }
            else if (root->left != NULL && root->right != NULL)
            {
                // searchMin
                // num = searchMax(root->left)
                // root->data = num;
                // return deleteNode(root->left,num);//250,275
            }
            else
            {
                if (root->left != NULL)
                {
                    // left is present
                    root->data = root->left->data;
                    // free(root->left);
                    // root->left = NULL;
                    // return root;
                    printf("\n%d is deleted...", num);
                    root->left = deleteNode(root->left, root->data);
                }
                else
                {
                    // right is present
                    root->data = root->right->data;
                    printf("\n%d is deleted...", num);
                    root->right = deleteNode(root->right, root->data);
                }
            }
        }
        else if (num > root->data)
        {
            root->right = deleteNode(root->right, num);
        }
        else
        {
            root->left = deleteNode(root->left, num);
        }
    }
    return root;
}
int main()
{
    int n = 7;
    int i, num;
    // for (i = 1; i <= n; i++)
    // {
    //     printf("\nEnter node value");
    //     scanf("%d", &num);
    //     root = addNode(root, num);
    // }

    root = addNode(root, 50);
    addNode(root, 400);
    addNode(root, 35);
    addNode(root, 37);
    addNode(root, 300);
    addNode(root, 500);
    addNode(root, 250);

    printf("\nInOrder: => ");
    inOrder(root); // 30

    printf("\npreOrder: => ");
    preOrder(root); // 30

    printf("\nPostOrder: => ");
    postOrder(root); // 30

    deleteNode(root, 300);
    printf("\nInOrder: => ");
    inOrder(root); // 30

    return 0;
}