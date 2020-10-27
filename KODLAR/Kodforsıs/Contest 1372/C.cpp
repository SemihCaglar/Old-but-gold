#include<iostream>
using namespace std;

int a[200000];

void coz(){
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	bool aa=false,b=false;
	int x,y;
	for(x=0;a[x]==x+1&&x<n;++x);
	if(x==n){
		cout<<0;
		return;
	}
	for(y=n-1;a[y]==y+1;--y);
		
	for(int i=x;i<=y;i++){
		if(a[i]==i+1)
			aa=true;
		else
			b=true;	
	}
	if(aa==true){
		if(b==true){
			cout<<2;
			return;
		}
		else{
			cout<<0;
			return;
		}
	}
	else{
		cout<<1;
		return;
	}	
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		coz();
		cout<<endl;
	}
	return 0;
}
