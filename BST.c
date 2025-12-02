
#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} node;

node *create()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    else if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void display(node *root)
{
    if(root==NULL) return;
    node *queue[100];
    int front=0, rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        node *curr=queue[front++];
        printf("%d ",curr->data);
        if(curr->left!=NULL) queue[rear++]=curr->left;
        if(curr->right!=NULL) queue[rear++]=curr->right;
    }
}

int main()
{
    char ch;
    node *root=NULL,*temp;
    do
    {
        temp=create();
        if(root==NULL) root=temp;
        else insert(root,temp);
        printf("Do you want to enter more(y/n)? ");
        scanf(" %c",&ch);
    } while(ch=='y' || ch=='Y');

    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\nLevel-order Display: ");
    display(root);
    printf("\n");
    return 0;
}

