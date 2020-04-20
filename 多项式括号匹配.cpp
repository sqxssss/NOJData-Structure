#include<stdio.h>
#include<stdlib.h>
#define N 20
#define SIZE 20
#define MORE 10
 
typedef struct
{
    char *base;
    char *top;
    int size;
}STACK;
 
void STACK_init(STACK *s, int size)
{
    s->base = (char *)malloc(size*sizeof(char));
    s->top = s->base;
    s->size = size;
}
 
void STACK_push(STACK *s, char ch)
{
    *(s->top) = ch;
    s->top ++;
}
 
char STACK_top(STACK *s)
{
    return *(s->top-1);
}
 
void STACK_pop(STACK *s)
{
    s->top --;
}
 
int STACK_empty(STACK *s)
{
    return s->top == s->base;
}
 
char pairs[300];
char str[100000];
int DaDaDa(const char *s)
{
   STACK stack;
   STACK_init(&stack,100000);
   for(;*s;++s)
   {
        if(*s == '(' || *s == '[' || *s == '{')
        {
            STACK_push(&stack, *s);
        }
        else if(*s == ')' || *s == ']' || *s == '}')
        {
            if(STACK_empty(&stack))
            {
                return 0;
            }
            if(STACK_top(&stack) != pairs[(int)*s])
            {
                return 0;
            }
            STACK_pop(&stack);
        }
   }
    return STACK_empty(&stack);
}
 
int main(void)
{
    pairs['('] = ')', pairs[')'] = '(';
    pairs['['] = ']', pairs[']'] = '[';
    pairs['{'] = '}', pairs['}'] = '{';
 
    gets(str);
    int paired = DaDaDa(str);
    printf(paired?"yes\n":"no\n");
    return 0;
}
