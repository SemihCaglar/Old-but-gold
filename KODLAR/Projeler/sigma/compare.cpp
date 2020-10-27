#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
	
	ifstream ort("ort.txt");
	double ans[70]={0};
	for(int i=0;ort>>ans[i];++i);
	ort.close();
	
	double a;
	ifstream output("Output2.txt");
	ofstream gg("gg.txt");
	double min=5;
	int base;
	for(int i=0;i<10029;++i){
	//	bool durum=true;
		double maxfark=-1;
		for(int j=0;output>>a,a!=-1;++j)
			if( abs(ans[j]-a)>maxfark )
				maxfark=abs(ans[j]-a);
		
	//	if(maxfark>0.07) durum=false;		
	//	if(durum) cout<<i+2<<endl;			
		if(maxfark<min){
			min=maxfark;
			base=i+2;
		}
	}
	output.close();
	
	//cout<<base<<endl;;
	
	ifstream outputt("Output2.txt");
	for(int i=0;i<10029;++i){
	//	bool durum=true;
		double maxfark=-1;
		for(int j=0;outputt>>a,a!=-1;++j)
			if( abs(ans[j]-a)>maxfark )
				maxfark=abs(ans[j]-a);
		
	//	if(maxfark>0.07) durum=false;		
	//	if(durum) cout<<i+2<<endl;			
		if(maxfark==min){
			cout<<i+2<<endl;
			gg<<i+2<<endl;
		}
	}	
}
