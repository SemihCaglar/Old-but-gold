#include<stdio.h>

int us(int taban,int kuvvet){
    int carpim=1;
	for(;kuvvet>0;kuvvet--)
		carpim*=taban;
	return carpim;          }
	
int onluk(int sayi,int taban){ //Onluk sisteme çevirme.
	int basamak=0;
	int i=1;
	for(;i<=sayi;i*=10)
		basamak++;
	
	int sonuc=0;
	i/=10;
	while(i>0){
		sonuc+= (sayi/i)*us(taban,--basamak);
		sayi%=i;
		i/=10;    }
		
	return sonuc;
}

int cevirme(int sayi,int taban){
	int yenibasamak=0; //Yeni sayının kaç basamaklı olması gerektiği.
 int x=1;
	for(;x<=sayi;x*=taban)
		yenibasamak++ ;
		
	int sonuc=0;
	while(yenibasamak>0){
		x/=taban;
   sonuc += (sayi/x)*us(10,--yenibasamak);
   sayi%=x;           }
	
	return sonuc;
}

int main(){
	printf("x tabanindaki y sayisini z tabaninda yazin.\n");
	int girdi[3];
	for(int i='x';i<='z';i++){
		printf("%c=? ",i);
		scanf("%d",&girdi[i-'x'] );  }
		
	printf("\nSonuc: %d",cevirme( onluk(girdi[1],girdi[0]) , girdi[2]));
  
}
