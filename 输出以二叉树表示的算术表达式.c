#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

BTNode *CreateTree()
{
    BTNode *root =(BTNode*)malloc(sizeof(BTNode));
    char s;
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

void print(BTNode *root)
{
    if(root->lchild)
    {
        print(root->lchild);
    }
    printf("%c",root->data);
    if(root->rchild)
    {
        print(root->rchild);
    }
}

int main()
{
    BTNode *root;
    root=CreateTree();
    print(root);
    return 0;
}
//
// Created by sqx08 on 2020/4/24.
//

