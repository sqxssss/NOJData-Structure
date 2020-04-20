#include<iostream>
using namespace std;
 int main(){
	int ary[1005];
	int n,m,i,tmp,flag=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ary[i];
	}
	cin>>m;
	for(i=0;i<n-1;i++){
		if(m<ary[0]){
			tmp=0;
			flag=1;
			break;
		}
		else if(m>=ary[i]&&m<=ary[i+1]){
			tmp=i+1;
			flag=1;
			break;
		}
	}
	if(flag){
		for(i=n;i>=tmp;i--){
		   ary[i]=ary[i-1];
     	}
	    ary[tmp]=m;
	}
	else{
		ary[n]=m;
	}
	cout<<ary[0];
	for(i=1;i<n+1;i++){
		cout<<" "<<ary[i];
	}
	cout<<endl;
	return 0;
}