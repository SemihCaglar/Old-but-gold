#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	
	long n,i;
	cin>>n;
	bool a=0;
	for(i=2;i<=sqrt(n);++i){
		if(n%i==0){
			a=1;
			break;
		}
	}
	if(a==0) i=n;
	long k=n/i;
	cout<<k<<' '<<n-k<<endl;		
		
	}

	return 0;	
}
