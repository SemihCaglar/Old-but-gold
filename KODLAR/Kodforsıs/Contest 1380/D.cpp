#include<iostream>
using namespace std;

int n,m;
unsigned long long int  x,k,y;
bool tercih;

unsigned long long int cost(int *a,int onceki,int index,bool&h){
	
	int buyuksayisi=0,adet;
	h=false;
	
	if(index==-1){
		if(onceki==n-1) return 0;
		for(int i=onceki+1;i<n;i++)
			if(a[i]>a[onceki]) ++buyuksayisi;
			adet=n-onceki-1;
	}
	else{
		for(int i=onceki;i<index;i++)
			if(a[i]>a[index]) ++buyuksayisi;
		adet=index-onceki;
	}
	if(buyuksayisi&&adet<k){
		h=true;
		return 0;
	}
	
	if(tercih==0)
		return (adet%k)*y + (adet/k)*x ;
	
	else{
		if(buyuksayisi==0) return adet*y;
		return (adet-k)*y + x;
	}
	
}

int main(){
	
	cin>>n>>m;
	cin>>x>>k>>y;
	int a[n],b[m];
	for(int i=0;i<n;++i)
		cin>>a[i];
	for(int i=0;i<m;++i)
		cin>>b[i];
	
	unsigned long long int cevap=0;
	int index=-1;
	tercih= y*k>x ? 0:1; // 0 ise fireball, 1 ise berserk.	
	bool h;
	
	for(int i=0;i<m;i++){
		
		int onceki=index+1;
		for(; a[index]!=b[i]&&index<n ; ++index);
		if(index>=n){
			cout<<-1;
			return 0;
		}
		unsigned long long int boj=cost(a,onceki,index,h);
		if(h){
			cout<<-1;
			return 0;
		}
		cevap+=boj;
			
	}
	unsigned long long int boj=cost(a,index,-1,h);
	if(h){
		cout<<-1;
		return 0;
	}
	cevap+=boj;		
	
	cout<<cevap;
	return 0;
}
