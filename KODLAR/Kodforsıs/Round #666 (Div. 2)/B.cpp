#include<iostream>
#include<algorithm>
#include<cmath>
#define ulli unsigned long long int
using namespace std;
int main(){
	int n;
	cin>>n;
	ulli a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+sizeof(a)/sizeof(a[0]));
	
	ulli cost,min;
	for(int c=1;c<1001;c++){
		cost=0;
		for(int i=0;i<n;i++){
			cost+=abs(a[i]-pow(c,i));
			//cout<<"bdhh "<<abs(a[i]-pow(c,i))<<endl;
		}
		if(c==1)
			min=cost;
		//cout<<cost<<"	";	
		if(cost<min){
			min=cost;
		}
	}
	cout<<min<<endl;
	
	
}
