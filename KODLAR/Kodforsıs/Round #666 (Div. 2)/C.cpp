#include<iostream>
#define lli long long int
using namespace std;
int main(){
	int n;
	cin>>n;
	lli ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
		
	if(n==1){
		cout<<1<<' '<<1<<endl;
		cout<<ar[0]*-1;
		cout<<endl<<1<<' '<<1<<endl;
		cout<<0;
		cout<<endl<<1<<' '<<1<<endl;
		cout<<0;
		return 0;
		
	}	
	
	cout<<1<<' '<<n-1<<endl;
	
	for(int i=0;i<n-1;i++){
		cout<<ar[i]%n*(n-1)<<' ';		
		ar[i]+=ar[i]%n*(n-1);
	}
	
	cout<<endl<<1<<' '<<n<<endl;		
	for(int i=0;i<n;i++)
		cout<<ar[i]*-1<<' ';
	
	cout<<endl<<n<<' '<<n<<endl;
	cout<<(ar[n-1]-n)*-1;	
	return 0;	
}
