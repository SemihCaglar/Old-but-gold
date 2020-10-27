#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

int main(){
	
	short n,m,k;
	cin>>n>>m>>k;
	short sx[k],sy[k],fx[k],fy[k];
	for(int i=0;i<k;i++)
		cin>>sx[i]>>sy[i];
	for(int i=0;i<k;i++)
		cin>>fx[i]>>fy[i];
		
	bool *ok=(bool*)calloc(k,1);
	short l,r,d,u;
	
	int s=2*m*n;
	short fin=0;
	string str;
	
	while(s--){
		
		l=r=d=u=0;
		
		for(int i=0;i<k;++i){
			if(sx[i]==fx[i]&&sy[i]==fy[i]&&ok[i]==false){
				ok[i]=true;
				++fin;
			}
			if(ok[i]==true) continue;
			
			if(sy[i]>fy[i]) l += 1;
			else if(sy[i]!=1) l += -1;
			
			if(sy[i]<fy[i]) r += 1;
			else if(sy[i]!=m) r+= -1;
			
			if(sx[i]>fx[i]) u += 1;
			else if(sx[i]!=1) u+= -1;
			
			if(sx[i]<fx[i]) d+= 1;
			else if(sx[i]!=n) d += -1;
			
		}
		if(fin==k) break;
				
		else if(r>=l&&r>=d&&r>=u){
			for(int i=0;i<k;i++)
				if(sy[i]!=m) sy[i]+=1;			
			str.append("R",0,1);
		}
		else if(d>=l&&d>=r&&d>=u){
			for(int i=0;i<k;i++)
				if(sx[i]!=n) sx[i]+=1;			
			str.append("D",0,1);
		}
		if(l>=r&&l>=u&&l>=d){
			for(int i=0;i<k;i++)
				if(sy[i]!=1) sy[i]-=1;
			str.append("L",0,1);	
		}				
		else{
			for(int i=0;i<k;i++)
				if(sx[i]!=1) sx[i]-=1;
			str.append("U",0,1);
		}
		
	}
//	if(fin<k&&s==-1) cout<<-1<<endl;
	cout<<str.length()<<endl<<str;			
	
}
