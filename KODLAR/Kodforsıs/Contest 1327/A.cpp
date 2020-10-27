#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		
		long n,k;
		cin>>n>>k;
		if(1LL*k*k<=1LL*n && k%2==n%2)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;		
		
	}
	return 0;
}
