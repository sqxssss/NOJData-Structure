#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node *next;
}LNode;
 
LNode* CreateLinkList(int n)
{
    LNode *head,*p,*q;
    int i;
    head=(LNode*)malloc(sizeof(LNode));
    head->next=NULL;
    p=head;
    q=p;//指针q始终指向链尾节点
    for(i=1;i<=n;i++)
    {
        p=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return head;
}
void Merge(LNode *A,LNode *B,LNode **C)
{
    LNode *p,*q,*s;
    p=A->next;
    q=B->next;
    *C=A;
    (*C)->next=NULL;
    free(B);
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<q->data)
        {
            s=p;
            p=p->next;
        }
        else
        {
            s=q;
            q=q->next;
        }
        s->next=(*C)->next;
        (*C)->next=s;
    }
    if(p==NULL)
    p=q;
    while(p!=NULL)
    {
        s=p;
        p=p->next;
        s->next=(*C)->next;
        (*C)->next=s;
    }
}
 
void print(LNode *p)
{
    p=p->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
 
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    LNode *A,*B,*C;
    A=CreateLinkList(m);
    B=CreateLinkList(n);
    Merge(A,B,&C);
    print(C);
    return 0;
}