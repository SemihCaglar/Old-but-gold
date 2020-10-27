#include<stdio.h>
int main(){
	int kenar;
	int yukseklik;
	
	printf("Kenar uzunlugu:");
	scanf("%d",&kenar);
	printf("Yukseklik:");
	scanf("%d",&yukseklik);
	
	float alan=kenar*yukseklik/2.0;
	printf("\nUcgenin alani:%.1f cm",alan);
	
	
	
}
