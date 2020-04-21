  /*#include<stdio.h>
#include<stdlib.h>
#define MAXIMUM 100
#define DataType int
typedef struct SeqQueue
{
    DataType q[MAXIMUM];
    int front,rear;
}SeqQueue,*PSeqQueue;
PSeqQueue createEmptyQueue_seq(void)
{
    PSeqQueue paxu;
    paxu=(struct SeqQueue*)malloc(sizeof(struct SeqQueue));
    if(paxu==NULL)
        printf("out space!");
    else
    {
        paxu->front=0;
        paxu->rear=0;
    }
    return paxu;
}
int isEmptyQueue_seq(PSeqQueue paxu)
{
    return (paxu->front==paxu->rear);
}
void enQueue_seq(PSeqQueue paxu,DataType x,int k)//队尾插入元素
{
    if((paxu->rear+1)%k==paxu->front)
        printf("yes\n");
    else
    {
        paxu->q[paxu->rear]=x;
        paxu->rear=(paxu->rear+1)%k;
    }
}
void deQueue_seq(PSeqQueue paxu,int k)
{
    if(isEmptyQueue_seq(paxu))
        printf("empty queue");
    else
        paxu->front=(paxu->front+1)%k;
}
DataType frontQueue_seq(PSeqQueue paxu)
{
    if(isEmptyQueue_seq(paxu))
    {
        printf("empty queue");
        return 0;
    }
    else
        return paxu->q[paxu->front];
}
int main()
{
    int k,i,s;
    scanf("%d",&k);
    PSeqQueue t;
    DataType e,c;//C 为返回的值
    t=createEmptyQueue_seq();
    scanf("%d",&s);
    for(i=0;i<k;i++)
        {
             scanf("%d",&e);
             enQueue_seq(t,e,k);
        }
    while(t->q[t->front]!=e)
       t->q[t->front]=t->q[t->front++];
    t->q[t->front]=t->q[t->front++];
    c=t->q[t->front];
    for(i=t->front;i<t->rear;i++)
    {
        printf("%d ",t->q[i]);
    }
    printf("\n%d",c);
        return 0;
}*/
 
#include<stdio.h>  
#include<stdlib.h>  
typedef struct{  
    int *Date;  
    int front;  
    int rear;  
    int length;  
    int max;  
} Queue;  
 
Queue* CreateQueue(int k)  
{  
    Queue *Q;  
    Q = (Queue*)malloc(sizeof(Queue));  
    Q->max = k + 1;  
    Q->length=0;  
    Q->Date = (int*)malloc(sizeof(int)*Q->max);  
    Q->front = Q->rear = 0;  
    return Q;  
}  
 
void AddQ(Queue *Q, int item)  
{  
    if((Q->rear+1)%Q->max == Q->front)  
    {  
        return;  
    }  
    else{  
        Q->rear = (Q->rear+1)%Q->max;  
        Q->Date[Q->rear] = item;  
        Q->length++;  
    }  
}  
 
void pop(Queue *Q)  
{  
    if(Q->rear == Q->front)  
    {  
        printf("队列为空\n");  
        return;  
    }  
    else  
    {  
        Q->front = (Q->front+1)%Q->max;  
        Q->length--;  
        return;  
    }  
}  
 
int top(Queue *Q)  
{  
    return Q->Date[Q->front];  
}  
 
void output(Queue *Q)  
{  
    while(Q->front!=Q->rear)  
    {  
        printf("%d ",Q->Date[Q->front]);  
        Q->front++;  
    }  
    printf("%d\n",Q->Date[Q->rear]);  
}  
 
int main()  
{  
    int num[1000]={0};  
    char s[10000];  
    char str[100];  
    int n,cnt=0;  
    scanf("%d",&n);  
    getchar();  
    Queue *q;  
    q=CreateQueue(n);  
    int i;  
    gets(s);  
    for(i=0;s[i];)  
    {  
        int t;  
        if (s[i] == ' ') {  
            i++;  
            continue;  
        }  
        else  
        {  
            for (int j = i; s[j] != ' ' && s[j]; j++)  
            {  
                num[cnt] = num[cnt] * 10 + (s[j] - '0');  
                t=j+1;  
            }  
            cnt++;  
            i=t;  
        }  
    }  
    for (int i = 0; i < cnt; i++)  
    {  
        AddQ(q, num[i]);  
        if (q->length == q->max - 1)  
            break;  
    }  
    scanf("%s",str);  
    int data;  
    scanf("%d",&data);  
    while (top(q) != data)  
    {  
        pop(q);  
    }  
    pop(q);  
    int t = top(q);  
    output(q);  
    printf("%d\n",t);  
    return 0;  
}  
 
