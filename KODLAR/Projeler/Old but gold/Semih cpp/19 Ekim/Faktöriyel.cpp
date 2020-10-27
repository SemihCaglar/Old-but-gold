#include<stdio.h>
int main(){
	int n,i,f;
	printf("Dogal sayi giriniz: ");
	scanf("%d",&n);
	i=n;
	f=1;
	
	while(i>1){
		f*=i;
		i--;
	}
	printf("%d!",n);
	printf("=%d",f);

}
