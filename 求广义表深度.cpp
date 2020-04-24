//
// Created by sqx08 on 2020/4/24.
//
#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct INode
{
    int tag;
    union
    {
        ElemType data;
        struct INode *head;
    }val;
    struct INode *tail;
}GLNode;

GLNode* CreateList(char *p)
{
    GLNode *g;
    char a=*p++;
    if(a!='\n')
    {
        g=(GLNode*)malloc(sizeof(GLNode));
        if(a=='(')
        {
            g->tag=1;
            g->val.head=CreateList(p);
        }
        else if(a==')')
        {
            g=NULL;
        }
        else
        {
            g->tag=0;
            g->val.data=a;
        }
    }
    else
    {
        g=NULL;
    }
    a=*p++;
    if(g!=NULL)
    {
        if(a==',')
        {
            g->tail=CreateList(p);
        }
        else
        {
            g->tail=NULL;
        }
        return g;
    }
}

int GLdepth(GLNode *g)
{
    GLNode *k;
    k=(GLNode*)malloc(sizeof(GLNode));
    int maxg=0,depth;
    if(g->tag==0)
    {
        return 0;
    }
    k=g->val.head;
    if(k==NULL)
    {
        return 1;
    }
    while(k!=NULL)
    {
        if(k->tag==1)
        {
            depth=GLdepth(k);
            if(depth>maxg)
                maxg=depth;
        }
        k=k->tail;
    }
    return (maxg+1);
}

int main()
{
    char s[1000];
    gets(s);
    char *p=s;
    int depth;
    GLNode *q;
    q=CreateList(p);
    depth=GLdepth(q);
    printf("%d\n%d",depth,depth);
    return 0;
}
