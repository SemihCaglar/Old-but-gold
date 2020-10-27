#include<iostream>
#include<cstdlib>
using namespace std;

void coz(){
	
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	short *harf=(short*)calloc('z'-'a',sizeof(short));
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i].length();++j){
			harf[s[i][j]-'a']++;
		}
	}
	for(int i=0;i<'z'-'a';i++)
		if(harf[i]%n){
			cout<<"NO"<<endl;
			return;
		}	
	cout<<"YES"<<endl;
}

int main(){
	
	int t;
	cin>>t;
	while(t--)
		coz();
	
}
