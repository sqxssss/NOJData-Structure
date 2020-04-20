#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 
typedef struct list
{
	char num;
	struct list* next;
}list;
 
typedef struct stack
{
	list* ptop;
	list* pbottom;
}stack;
 
void init(stack* pstack);
void push(stack* pstack,int value);
void pop(stack* stack);
 
//栈的初始化
void init(stack* pstack)
{
	pstack->pbottom = (list* )malloc(sizeof(list));
	if(pstack->pbottom == NULL)
	{
		printf("内存分配失败，程序退出");
		exit(1);
	}
	else
	{
		pstack->ptop = pstack->pbottom;
		pstack->pbottom->next = NULL;//将栈底最后一个元素的下一个指针设为NULL
	}
}
//将某个元素压入栈中
void push(stack* pstack,char value)
{
	list* pnew = (list* )malloc(sizeof(list));
	pnew->num = value;
	pnew->next = pstack->ptop;
	pstack->ptop = pnew;
}
//栈顶元素出栈
void pop(stack* stack)
{
	list* p;
	p = stack->ptop;
	stack->ptop = stack->ptop->next;
	free(p);
}
//输入字符串
int main()
{
	stack* s;
	s = (stack*)malloc(sizeof(stack));
	char x[1000];
	char sign[100];
	int k = 0;
	scanf("%s",x);
	for(int i = 0;i < strlen(x);i++)
	{
		if(x[i] == '('||x[i] == ')'||x[i] == '['||x[i] == ']'||x[i] == '{'||x[i] == '}')
		{
			sign[k] = x[i];
			k++;
		}
	}
	init(s);
	for(int i = 0;i < strlen(sign);i++)
	{
		if(sign[i] == '('||sign[i] == '['||sign[i] == '{')
		{
			push(s,sign[i]);
		}
		if(sign[i] == ')')
		{
			if(s->ptop->num == '(')
			{
				pop(s);
			}
			else
			{
				printf("no\n");
				return 0;
			}
		}
		if(sign[i] == ']')
		{
			if(s->ptop->num == '[')
			{
				pop(s);
			}
			else
			{
				printf("no\n");
				return 0;
			}
		}
		if(sign[i] == '}')
		{
			if(s->ptop->num == '{')
			{
				pop(s);
			}
			else
			{
				printf("no\n");
				return 0;
			}
		}
	}
	if(s->ptop == s->pbottom)
	{
		printf("yes\n");
		return 0;
	}
}
