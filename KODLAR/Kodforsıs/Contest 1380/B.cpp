#include<iostream>
using namespace std;

struct oyun{
	int R;
	int P;
	int S;
};

char g(int p,int r,int s){
	if(p>=r&&p>=s) return 'P';
	if(r>=p&&r>=s) return 'R';
	return 'S';
} 


void coz(){
	string s;
	oyun rps;
	rps.P=rps.S=rps.R=0;
	cin>>s;

	for(int j=0;j<s.length();++j){
		int q=j;
		if( s[q]=='R')
			rps.P++;
		if(s[q]=='P')
			rps.S++;
		if(s[q]=='S')
			rps.R++;		
		
	}
	char sem=g(rps.P,rps.R,rps.S);	
	for(int i=0;i<s.length();++i)
		cout<<sem;	
	cout<<endl;		
	
	
}

int main(){
	
	int t;
	cin>>t;
	while(t--)
		coz();
	return 0;	
	
}
