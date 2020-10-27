#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int t;
	cin>>t;
	sem:
	while(t--){
		
		int n;
		cin>>n;
		int *p=(int*)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
			cin>>p[i];
			
		int i,jj,k;	
		
		for(int j=1;j<n-1;++j){
			bool c=false;
			for(int a=j-1;a>=0;--a){
				if(p[a]<p[j]){
					i=a;
					jj=j;
					c=true;
				}
			}
			if(c==false) continue;
			c=false;
			for(int b=j+1;b<n;++b){
				if(p[b]<p[j]){
					k=b;
					c=true;
				}
			}
			if(c==true){
				cout<<"YES"<<endl<<i+1<<' '<<j+1<<' '<<k+1<<endl;
				goto sem;
			}
		}
		cout<<"NO"<<endl;			
		
	}
}
