#include<iostream>
using namespace std;

void coz(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cout<<1<<' ';
	cout<<endl;	
}

int main(){
	int t;
	cin>>t;
	while(t--)
		coz();
	return 0;		
}
