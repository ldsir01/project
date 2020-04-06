#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node* lc;
    struct node* rc;
}node;
void preorder(node* root)
{
    if (root==NULL)
    return;
    printf ("%d ",root->key);
    preorder(root->lc);
    preorder(root->rc);
}
void print(node* root,int level)
{
    if (root==NULL)
    return;
    print(root->rc,level+1);
    for (int i=0;i<=level;i++)
    printf ("   ");
    printf("%d\n",root->key);
    print(root->lc,level+1);
}
node* create(int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->lc=NULL;
    temp->rc=NULL;
    temp->key=data;
    return temp;
}
int main(void)
{
    //hard code for cretion of tree 
    node* root=create(1);
    root->lc=create(2);
    root->rc=create(3);
    root->lc->lc=create(4);
    root->lc->rc=create(5);
    root->rc->lc=create(6);
    root->rc->rc=create(7);
    //printing tree
    print(root,0);
    //preorder traversal
    preorder(root);
}