#include<stdio.h>
#include<stdlib.h>
 
void search(int A[100],int B[100],int C[100],int a,int b,int c)
{
 
	int i=0,j=0,k=0,m,count=0;
	for(i=0; A[i];i++)
	{
		while( B[j] < A[i] && B[j] != B[b-1]) j++;
		while( C[k] < A[i] && C[k] != C[c-1]) k++;
		if( B[j] == A[i] && C[k] == A[i] )
        {
            for(m=i;m<a-1;m++)
            {
                A[m]=A[m+1];
            }
             count++;
        }
	}
 
		for(i=0;i<a-count;i++)
	printf("%d ",A[i]);
}
int main()
{
	int m,n,p,i;
	scanf("%d%d%d",&m,&n,&p);
	int a[100],b[100],c[100];
		for(i=0;i<m;i++)
	scanf("%d",&a[i]);
		for(i=0;i<n;i++)
	scanf("%d",&b[i]);
		for(i=0;i<p;i++)
	scanf("%d",&c[i]);
	search(a,b,c,m,n,p);
	return 0;
}