#include<iostream>
#include<cstdlib>
using namespace std;

void f(){
	
	int n;
	cin>>n;
	cout<<"heyyy";
	int princess=-1,prince=-1;
	bool *pr=(bool*)calloc(n,1);
	
	for(int i=0;i<n;++i){
		int k;
		cin>>k;
		cout<<"yihu";
		bool durum=true;
		
		while(k&&durum){
			int a;
			cin>>a;
			if(pr[a-1]==0){
				durum=false;
				pr[a-1]=1;
				for(int s=0;s<k-1;++s)
					cin>>a;	
				break;
			}
			--k;
		}
		if(k) continue;
		else{
			princess=i+1;
			for(++i;i<n;++i){
				cin>>k;
				int a;
				while(k--)
					cin>>a;
			}
			break;
		}		

	}
	if(princess!=-1){
		
		cout<<"IMPROVE"<<endl;
		for(int i=0;i<n;++i){
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
}

int main(){
	int t;
	cin>>t;
	while(t--)
		f();
	return 0;	
}
