#include<stdio.h>
int a,b,c;
int efruz(int n){
	switch(n){
		case 1: return a;
		case 2: return b;
		case 3: return c;
		default: return efruz(n-1)+efruz(n-2)+efruz(n-3);
	}
}

int main(){
	int n;
	printf("1. terimi a, 2. terimi b, 3. terimi c olan Efruz serisinin n. terimini bul.");
	printf("\nn,a,b,c degerlerini giriniz: ");
	scanf("%d%d%d%d",&n,&a,&b,&c);
	printf("\nSonuc: %d",efruz(n));
}
