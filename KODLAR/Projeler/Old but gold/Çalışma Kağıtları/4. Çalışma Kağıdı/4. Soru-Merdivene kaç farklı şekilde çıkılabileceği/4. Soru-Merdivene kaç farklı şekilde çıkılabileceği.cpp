#include<stdio.h>

int fibo(int adim){  //1 2 3 5 8 diye giden dizi.
	if(adim==1 || adim==2)
		return adim;
	
	return fibo(adim-1)+fibo(adim-2);
}

int main(){
	int n;
	printf("Basamak sayisi? ");
	scanf("%d",&n);
	printf("Sonuc: %d",fibo(n));
	
}
