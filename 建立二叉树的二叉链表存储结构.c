//
// Created by sqx08 on 2020/4/24.
//
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
    char c1,c2;
    BTNode *q;
    q=(BTNode*)malloc(sizeof(BTNode));
    q->lchild=NULL;
    q->rchild=NULL;
    c1=getchar();
    c2=getchar();
    if(c1==',')
    {
        q->data=c2;
        c1=getchar();
        if(c1=='(')
        {
            q->lchild=CreateTree();
            q->rchild=CreateTree();
        }
    }
    else
    {
        q->data=c1;
        if(c2=='(')
        {
            q->lchild=CreateTree();
            q->rchild=CreateTree();
        }
    }
    return q;
}

void PrintTree(BTNode *q)
{
    printf("%c",q->data);
    if(q->lchild)
        PrintTree(q->lchild);
    if(q->rchild)
        PrintTree(q->rchild);
}

int main()
{
    BTNode *q=(BTNode*)malloc(sizeof(BTNode));
    q=CreateTree();
    PrintTree(q);
    return 0;
}
