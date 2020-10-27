#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

void coz(){
	
	int n;
	long x;
	cin>>n>>x;
	long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	{int nn=sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+nn); }
	
	int index=0;
	int gereken;
	int cevap=0;
	
	while(index<n){
		gereken=ceil(x/1.0/arr[index]);
		if(index+gereken>n){
			index++;
			continue;
		}
	
		if(arr[index+1]*(gereken-1)>=x){
			index=index+1;
			if(index>n) break;
			gereken=ceil(x/1.0/arr[index]);
			continue;
		}
		if(arr[index]*gereken>=x){
			cevap+=1;
			index+=gereken;
			if(index>n) break;
			gereken=ceil(x/1.0/arr[index]);
		}
		
	}
	
	cout<<cevap<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--)
		coz();
	
	
}
