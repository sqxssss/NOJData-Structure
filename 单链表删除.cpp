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
    q=p;
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
 
void del(LNode *s,LNode *pa)
{
    LNode *q;
    q=pa;
    s->next=pa->next;
    pa=pa->next;
    free(q);
}
 
void search(LNode *A,LNode *B,LNode *C)
{
 for(;((A)&&((A->next)));)
    {
 
        while(((B)&&((B->next))) && (((B)->next->data)) < (((A)->next->data))) B = ((B)->next);
        while(((C)&&((C->next))) && (((C)->next->data)) < (((A)->next->data))) C = ((C)->next);
        if(((B)&&((B->next))) && ((C)&&((C->next))) && ((A)&&((A->next))) &&
            (((B)->next->data)) == (((A)->next->data)) && (((C)->next->data)) == (((A)->next->data)))
            {
                del((A),(A)->next);
            }
        else
        {
            A = ((A)->next);
        }
    }
}
 
void print(LNode *p)
{
    LNode *q;
    q=p->next;
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}
 
int main()
{
    LNode *A,*B,*C;
    int m,n,p;
    scanf("%d%d%d",&m,&n,&p);
    A=CreateLinkList(m);
    B=CreateLinkList(n);
    C=CreateLinkList(p);
    search(A,B,C);
    print(A);
    return 0;
}