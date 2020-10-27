#include<stdio.h>
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
double array[11000][66]={0};

long double round(long double a,int n){
  char s[400];
  a+=5*pow(10,-n-1);
  sprintf(s,"%.*f",n,a);
  sscanf(s,"%f",&a);
  return a;
}

int main(){
	int line=0;
	double a;
	int cnt=0;
	ifstream myfile("Output2.txt");
	double ans[70]={0};	
	while(myfile>>a){
		
		if(a==-1){
			line++;
			cnt=0;
			continue;
		}
		array[line][cnt]=a;
		cnt++;
	}
	myfile.close();
	
	for(int i=0;i<66;i++){
		long double sum=0.0;
		for(int j=0;j<10029;++j){
			sum+=array[j][i];
		}
		long double ho=sum/10029;
		ans[i]=round(ho,5);
		//ans[i]=ho;
	}

	FILE*ort=fopen("ort.txt","w");
	for(int i=0;i<66;++i)
		fprintf(ort,"%.5lf ",ans[i]);
	fclose(ort);
	return 0;
}
