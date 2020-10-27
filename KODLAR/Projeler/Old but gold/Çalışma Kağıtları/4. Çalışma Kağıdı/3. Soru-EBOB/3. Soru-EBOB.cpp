#include<stdio.h>

int ebob(int x,int y){  //Öklid Algoritmasý'ndan yola çýktým.
	if(x%y==0)
		return y;
		
	if(x/y==0)
		return 1;
		
	return ebob(y,x%y);
}

int main(){
	int a,b;
	printf("EBOB'u bulunacak iki sayi giriniz: ");
	scanf("%d%d",&a,&b);
	if (a>b)
		printf("\nSonuc: %d",ebob(a,b));
	else 
		printf("\nSonuc: %d",ebob(b,a));
}
