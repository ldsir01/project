#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node* lchild;
    struct node* rchild;
}node;
void pre(node* root)
{
    if (root==NULL)
    return;
    pre(root->lchild);
    pre(root->rchild);
    printf ("%d ",root->key);
}
void print(node* root,int level)
{
    if (root==NULL)
    return;
    print(root->rchild,level+1);
    for (int i=0;i<=level;i++)
    printf ("   ");
    printf("%d\n",root->key);
    print(root->lchild,level+1);
}
node* create(int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->lchild=NULL;
    temp->rchild=NULL;
    temp->key=data;
    return temp;
}
int main(void)
{
    //hard code for cretion of tree 
    node* root=create(1);
    root->lchild=create(2);
    root->rchild=create(3);
    root->lchild->lchild=create(4);
    root->lchild->rchild=create(5);
    root->rchild->lchild=create(6);
    root->rchild->rchild=create(7);
    //printing tree
    print(root,0);
    //pre traversal
    pre(root);
}