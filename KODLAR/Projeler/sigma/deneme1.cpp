#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>

typedef long double ld;
using namespace std;

const ld PI=0.34874987534895783495873240710491;// 0.94367327628732;//; 
FILE *out=fopen("Output2.txt","w");

ld round(ld a,int n){
  char s[40];
  a+=5*pow(10,-n-1);
  sprintf(s,"%.*f",n,a);
  sscanf(s,"%f",&a);
  return a;
}

class Song{
	
	public:
		Song(){
			//ar=(ld*)malloc(sizeof(ld));
		}
		~Song(){
			free(ar);
		}
		
		void convertbase(){
			int basamak=int( log2l(10)/log2l(base)*15 );
			ar=(ld*)calloc(basamak,sizeof(ld));
	
			ld num=PI;
			for(int i=0;i<basamak;++i){
				int oluru=num/pow(base,-(i+1));
				if(oluru==0) continue;
				ar[i]=oluru;
				num-=pow(base,-(i+1))*oluru;
			}
			// Üstteki for çalýþýyor... No problem...
			for(int i=0;i<basamak;++i)
				for(int j=0;j<log2l(base);++j)
				//cout<<(ar[i]+1)/base<<' ';
				fprintf(out,"%.5Lf ",(ar[i])/base);
		}		
		
		ld *ar;
		int base;
		
};

int main(){

const int N=100000;
Song array[N];
	
for(int i=2;i<=10030;++i){
	
	array[i].base=i;
	array[i].convertbase();
	cout<<endl;
	fprintf(out,"-1\n");
	
}	
fclose(out);	
	
}
