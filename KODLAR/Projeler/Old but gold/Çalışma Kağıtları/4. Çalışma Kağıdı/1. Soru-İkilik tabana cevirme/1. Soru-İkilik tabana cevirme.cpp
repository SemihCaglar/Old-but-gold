#include<stdio.h>
#include<math.h>

int cevirme(int sayi){//Ýkilik sisteme çevirme
	int yenibasamak=0; //Yeni sayýnýn kaç basamaklý olmasý gerektiði.
    int x=1;
	for(;x<=sayi;x*=2)
		yenibasamak++ ;
		
	int sonuc=0;
	while(yenibasamak){
	x/=2;
    sonuc += (sayi/x)*pow(10,--yenibasamak);
    sayi%=x;           }
	
	return sonuc;
}

int main(){
	int semih;
	printf("Ikilik tabana cevrilecek sayiyi giriniz: ");
	scanf("%d",&semih);
	printf("\nSonuc: %d",cevirme(semih));
	
}
