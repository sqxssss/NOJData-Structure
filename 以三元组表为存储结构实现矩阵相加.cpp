/*#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int row;
	int col;
	int num;
}node;
typedef struct
{
	node matrix1[100];
	node matrix2[100];
	int cnt1;
	int cnt2;
}matrix;
void init(matrix *p)
{
	int x1,x2;
	scanf("%d%d",&x1,&x2);
	p->cnt1=x1;
	p->cnt2=x2;
	for(int i=0;i<p->cnt1;i++)
	{
		scanf("%d%d%d",&p->matrix1[i].row,&p->matrix1[i].col,&p->matrix1[i].num);
	}
	for(int i=0;i<p->cnt2;i++)
	{
		scanf("%d%d%d",&p->matrix2[i].row,&p->matrix2[i].col,&p->matrix2[i].num);
	}
}
void add(matrix *p)
{
	int i,j,k,t,flag;
	int temp;
	for(i=0;i<p->cnt2;i++)
	{
		flag=1;
		for(j=0;j<p->cnt1;j++)
		{
			if(p->matrix1[i].row==p->matrix2[i].row && p->matrix1[i].col==p->matrix2[i].col)
			{
				p->matrix1[i].num += p->matrix2[i].num;
				if(p->matrix1[i].num == 0)
				{
					for(k=j;k<p->cnt1-1;k++)
					{
						p->matrix1[k].row=p->matrix1[k+1].row;
						p->matrix1[k].col=p->matrix1[k+1].col;
						p->matrix1[k].num=p->matrix1[k+1].num;
				    }
				    p->cnt1=p->cnt1-1;
				}
				flag=0;
				break;
			}
		}
		if(flag)
		{
			t=p->cnt1-1;
			p->matrix1[++t].row=p->matrix2[i].row;
			p->matrix1[t].col=p->matrix2[i].col;
			p->matrix1[t].num=p->matrix2[i].num;
			p->cnt1++;
		}
	}
		
	for(i=0;i<p->cnt1-1;i++)
		for(j=i;j<p->cnt1;j++)
		{
			if(p->matrix1[i].row > p->matrix1[j].row)
			{
				temp=p->matrix1[i].row;
				p->matrix1[i].row=p->matrix1[j].row;
				p->matrix1[j].row=temp;
				temp=p->matrix1[i].col;
				p->matrix1[i].col=p->matrix1[j].col;
				p->matrix1[j].col=temp;
				temp=p->matrix1[i].num;
				p->matrix1[i].num=p->matrix1[j].num;
				p->matrix1[j].num=temp;
			}
		}
	for(i=0;i<p->cnt1-1;i++)
		for(j=i;j<p->cnt1+1;j++)
		{
			if(p->matrix1[i].row==p->matrix1[j].row && p->matrix1[i].col>p->matrix1[j].col)
			{
				temp=p->matrix1[i].col;
				p->matrix1[i].col=p->matrix1[j].col;
				p->matrix1[j].col=temp;
				temp=p->matrix1[i].num;
				p->matrix1[i].num=p->matrix1[j].num;
				p->matrix1[j].num=temp;
			}
		}						
}
void output(matrix *p)
{
	int temp=0;
	while((p->cnt1)--)
	{
		 printf("%d %d %d\n",p->matrix1[temp].row,p->matrix1[temp].col,p->matrix1[temp].num);
		 temp++;
	}
	printf("\n");
}
int main()
{
	matrix *p=(matrix *)malloc(sizeof(matrix));
	init(p);
	add(p);
	output(p);
	return 0;
}
*/
 
 
#include<stdio.h>
#include<stdlib.h>
#define Max 10000
 
typedef struct node{
	int row;
	int col;
	int num;
}node;
 
typedef struct matrix{
	int cnt1, cnt2;
	struct node triad1[Max];
	struct node triad2[Max];
}matrix;
 
void init(matrix *list){
	int a, b, x, y ,z;
	int i;
	scanf("%d%d", &a, &b);
	list->cnt1 = a;
	list->cnt2 = b;
	for(i = 0; i < a; i++){
	    scanf("%d%d%d", &x, &y, &z);
		list->triad1[i].row = x;
		list->triad1[i].col = y;
		list->triad1[i].num = z;
	}
	for(i = 0; i < b; i++){
		scanf("%d%d%d", &x, &y, &z);
	    list->triad2[i].row = x;
		list->triad2[i].col = y;
		list->triad2[i].num = z;
	}
}
 
void dele(matrix *list, int x){
	int i;
	for(i = x; i < list->cnt1-1; i++){
	    list->triad1[i] = list->triad1[i+1];
	}
	list->cnt1--;
}
 
void insert(matrix *list, int x){
	list->triad1[list->cnt1] = list->triad2[x]; 
	list->cnt1++;
}
 
void add(matrix *list){
	int i, j, x, y, flag;
	x = list->cnt1;
	y = list->cnt2;
	for(i = 0; i < y; i++){
		flag = 1;
		for(j = 0; j < x; j++){
			if(list->triad2[i].row == list->triad1[j].row && list->triad2[i].col == list->triad1[j].col){
			    list->triad1[j].num += list->triad2[i].num;
				if(list->triad1[j].num == 0){
				    dele(list, j);
				}
				flag = 0;
				break;
			}
		}
		if(flag){
		     insert(list, i);
		}
	}
}
 
void output(matrix *list){
	int i, x, y, z;
	for(i = 0; i <list->cnt1; i++){
	    x = list->triad1[i].row;
		y = list->triad1[i].col;
		z = list->triad1[i].num;
		printf("%d %d %d\n", x, y, z);
	}
}
 
void sort(matrix *list){
    int i, j;
	node p;
	for(i = 0; i < list->cnt1-1; i++){
		for(j = i; j < list->cnt1-i-1; j++){
			if(list->triad1[j].row > list->triad1[j+1].row){
			     p = list->triad1[j];
				 list->triad1[j] = list->triad1[j+1]; 
				 list->triad1[j+1] = p;
			}
		}
	}
	for(i = 0; i < list->cnt1-1; i++){
		for(j = i; j < list->cnt1-i-1; j++){
			if(list->triad1[j].row == list->triad1[j+1].row && list->triad1[j].col > list->triad1[j+1].col){
			     p = list->triad1[j];
				 list->triad1[j] = list->triad1[j+1];
				 list->triad1[j+1] = p;
			}
		}
	}
}
 
int main(){
	matrix *list = (matrix*)malloc(sizeof(matrix));
	init(list);
	add(list);
	sort(list);
	output(list);
	return 0;
}
