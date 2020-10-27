#include<iostream>
#include<cstdlib>
using namespace std;

void f(){
	
	long n;
	cin>>n;
	long princess=-1,prince=-1;
	bool *pr=(bool*)calloc(n,1);
	
	for(long i=0;i<n;++i){
		long k;
		cin>>k;
		bool durum=true;
		
		while(k&&durum){
			long a;
			cin>>a;
			if(pr[a-1]==0){
				durum=false;
				pr[a-1]=1;
				for(long s=0;s<k-1;++s)
					cin>>a;	
				break;
			}
			--k;
		}
		if(k) continue;
		else{
			princess=i+1;
		}		

	}
	if(princess!=-1){
		
		cout<<"IMPROVE"<<endl;
		for(long i=0;i<n;++i){
			if(pr[i]==0){
				prince=i+1;
				break;
			}
		}
		cout<<princess<<' '<<prince;
		
	}
	else
		cout<<"OPTIMAL";
		
	cout<<endl;
	free(pr);
}

int main(){
	int t;
	cin>>t;
	while(t--)
		f();
	return 0;	
}
