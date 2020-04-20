#include<stdlib.h>
#include<iostream>
using namespace std;
 
typedef struct node
{
    int num;
	node* next;
}node;
 
int n;
int ray[1005];
 
 void array(){
	int i;
	cout<<ray[n-1];
	for(i=n-2;i>=0;i--){
		cout<<" "<<ray[i]; 
	}
	cout<<endl;
}
void list()
{
	node *head,*p,*q;
	int i;
	head=(node*)malloc(sizeof(node));    /*创建头节点*/
	/*赋值*/ 
	q=head;
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		p->num=ray[i];
		q->next=p;
		q=p;
	}
	q->next=NULL;
	/*头插法*/
	p=head->next;
	head->next=NULL; 
	while(p)
	{
		q=p;
		p=p->next;
		q->next=head->next;
		head->next=q;
	}
	q=head->next;
	while(1){
		if(q->next==NULL)
		{
			cout<<q->num<<endl;
			break;
		}
		else
		{
			cout<<q->num<<" ";
			q=q->next;
		}
	}
}
 
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ray[i];
	}
	array();
	list();
	return 0;
} 