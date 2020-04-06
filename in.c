#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int count;
    struct node* lc;
    struct node* rc;
}node;

void print(node* root,int level)
{
    if (root==NULL)
    return;
    print(root->rc,level+1);
    for (int i=0;i<=level;i++)
    printf ("   ");
    printf("%d\n",root->count);
    print(root->lc,level+1);
}


void preorder(node* root)
{
    if (root==NULL)
    return;
    preorder(root->lc);
    printf ("%d ",root->count);
    preorder(root->rc);
}


node* create(int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->lc=NULL;
    temp->rc=NULL;
    temp->count=data;
    return temp;
}


int main(void)
{
    node* root=create(1);
    root->lc=create(2);
    root->rc=create(3);
    root->lc->lc=create(4);
    root->lc->rc=create(5);
    root->rc->lc=create(6);
    root->rc->rc=create(7);
    print(root,0);
    preorder(root);
}