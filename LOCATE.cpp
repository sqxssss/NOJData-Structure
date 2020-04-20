#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	char s;
	int num;
	struct list *next,*pre;
}list;
 
list* init()
{
	list* head;
	head = (list* )malloc(sizeof(list));
	head->pre = NULL;
	return head;
}
 
list* add(list* tail,char c)
{
	list* p = (list* )malloc(sizeof(list));
	p->s = c;
	p->num = 0;
	tail->next = p;
	p->pre = tail;
	tail = p;
	return tail;
}
 
list* travel(list* head,int n,int m)
{
	char c;
	list *p, *q, *h;
	p = head->next;
	int i = 0;
	while(1)
	{
		c = getchar();
		if(c != ' '&&c != '\n')
		{
			while(p)
			{
				if(p->s == c)
				{
					(p->num)++;
				}
				p = p->next;
			}
			p = head->next;
			i++;
			if(i == n)
			{
				break;
			}
		}
	}
/*
	while(p)
	{
		printf("%c ",p->s);
		printf("%d ",p->num);
		p = p->next ;
	}
}*/
	for(int i = 0;i < m;i++)
	{	
		p = head->next;
		h = p;
		q = head->next;
		while(q)
		{
			if(h->num < q->num)
			{
				h = q;
			}
			q = q->next;
		}
		printf("%c ",h->s);
		if(h->next == NULL)
		{
			h->pre->next = NULL;
		}
		else
		{
			if(h->pre == NULL)
			{
				head = head->next;
				head->pre = NULL;
			}
			else
			{
				h->next->pre = h->pre;
				h->pre->next = h->next;
			}
		}
		free(h);
	}
	printf("\n");
	return 0;
}
 
int main()
{
	list *head,*tail;
	head = init();
	tail = head;
	int m,n;
	scanf("%d%d",&m,&n);
	int i = 0;
	char c;
	while(1)
	{
		c = getchar();
		if(c != ' '&&c != '\n')
		{
			tail = add(tail,c);
			i++;
			if(i == m)
			{
				break;
			}
		}
	}
	tail->next = NULL;
	travel(head,n,m);
	return 0;
}  
