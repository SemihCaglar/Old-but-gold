#include<stdio.h>

int fakt(int n){  //Faktöriyel
	return (n==0 || n==1)? 1 : n*fakt(n-1); }
	
int tekper(int x,int y){  //Tekrarlý permütasyon
	return fakt(x+y)/fakt(x)/fakt(y);   }

int main(){
	int n,beslik,onluk=0,sonuc=0;
	printf("Cikolatanin fiyati? ");
	scanf("%d",&n);
	
	while(n>=0){
		beslik=n/5;
		sonuc+=tekper(beslik,onluk);
		n-=10;
		onluk++;
	}
		
	printf("Sonuc: %d",sonuc);

}
