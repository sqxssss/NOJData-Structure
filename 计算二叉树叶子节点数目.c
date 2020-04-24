#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

BTNode *CreateTree()
{
    char s;
    BTNode *root = (BTNode*)malloc(sizeof(BTNode));
    s=getchar();
    if(s=='#')
        return NULL;
    else
    {
        root->data=s;
        root->lchild=CreateTree();
        root->rchild=CreateTree();
    }
    return root;
}

int DepthTree(BTNode *root)
{
    if(!root)
    {
        return 0;
    }
    else
    {
        if((!root->lchild)&&(!root->rchild))
        {
            return 1;
        }
        else
        {
            return (DepthTree(root->lchild)+DepthTree(root->rchild));
        }
    }
}

int main()
{
    BTNode *root;
    root=CreateTree();
    int depth;
    depth=DepthTree(root);
    printf("%d\n",depth);
    return 0;
}
//
// Created by sqx08 on 2020/4/24.
//

