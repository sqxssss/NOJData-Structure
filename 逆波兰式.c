#include <stdio.h>
#include <stdlib.h>
#define Stack_Init_Size 20
#define Stack_Increasement 10
 
typedef char Elemtype;
typedef struct{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
}sqStack;
 
void initStack(sqStack *s)
{
    s->base=(Elemtype *)malloc(Stack_Init_Size*sizeof(Elemtype));
    if(!s->base)
    {
        return;
    }
    s->top=s->base;
    s->stacksize=Stack_Init_Size;
}
 
void push(sqStack *s,Elemtype e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(Elemtype *)realloc(s->base,(Stack_Increasement+s->stacksize)*sizeof(Elemtype));
        if(!s->base)
        {
            return;
        }
    }
    *(s->top)=e;
    s->top++;
}
 
void pop(sqStack *s,Elemtype *e)
{
    if(s->top == s->base)
    {
        return;
    }
    s->top--;
    *e=*(s->top);
}
 
int stackLen(sqStack s)
{
    return (s.top-s.base);
}
 
int isEmpty(sqStack s)
{
    return (s.base==s.top);
}
 
int main()
{
    sqStack s;
    initStack(&s);
    char c,e;
    scanf("%c",&c);
    while(c!='\r')
    {
        while('a'<=c&&c<='z')
        {
            printf("%c",c);
            scanf("%c",&c);  //如果此刻输入\r，则外层以\r为结束条件的循环会无法结束，因为后面有读入的语句，此时读入的\r会被“覆盖”，所以外层循环内的要判断读入的c是否是\r
        }
        if(')'==c)
        {
            pop(&s,&e);
            while( '(' != e )
            {
                printf("%c",e);
                pop(&s,&e);
            }
        }
        else if('+'==c ||'-'==c)
        {
            if(isEmpty(s))
            {
                push(&s,c);
            }
            else
            {
                do
                {
                    pop(&s,&e);
                    if( '(' == e )
                    {
                       push(&s,e);
                    }
                    else
                    {
                        printf("%c",e);
                    }
                }while(!isEmpty(s) && '('!=e);
                push(&s,c);
            }
        }
        else if( '*' == c || '/' == c || '(' == c )
        {
             push(&s,c);
        }
        else
        {
            break;
        }
        scanf("%c",&c);
    }
    while(!isEmpty(s))
    {
        pop(&s,&e);
        printf("%c ",e);
    }
	printf("\n");
    return 0;
}
