#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
 
typedef struct SeqQueue
{
    int front;
    int rear;
    int q[max];
}SeqQueue,*PSeqQueue;
 
void CreateQueue(PSeqQueue *Q)
{
    *Q=(PSeqQueue)malloc(sizeof(SeqQueue));
    if((Q)==NULL);
    else
    {
        (*Q)->rear=0;
        (*Q)->front=(*Q)->rear;  //循环队列要取余，所以要从0开始
    }
}
 
void Fibonacci(int num,int k,PSeqQueue s)
{
        int i;
    for(i=0;i<k-1;i++)
    s->q[i]=0;
    s->q[i]=1;
    s->rear=k-1;
    int sum=1;
    while(sum<=num)
    {
        s->rear=(s->rear+1)%k;
        s->q[s->rear]=sum;          //第一次的运算要自己初始算，如果用sum做为结束，sum==1,符合k阶斐波那契数列法则
        s->front=(s->front+1)%k;  //始终保持rear与front相差k.
        sum=0;
        for(i=0;i<k;i++)
        {
            sum+=s->q[i];
        }
    }
    int cnt=0;
    while(cnt<k-1)
    {
        printf("%d ",s->q[(s->front+cnt)%k]);
        cnt++;
    }
    printf("%d\n",s->q[(s->front+cnt)%k]);
}
 
int main()
{
    PSeqQueue s;
    CreateQueue(&s);
    int k,value;
    scanf("%d%d",&value,&k);
    Fibonacci(value,k,s);
    return 0;
}
