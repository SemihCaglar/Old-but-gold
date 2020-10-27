#include<stdio.h>
#include<math.h>

int cevirme(int sayi){//Ýkilik sisteme çevirme
	int yenibasamak=0; //Yeni sayýnýn kaç basamaklý olmasý gerektiði.
    int x=1;
	for(;x<=sayi;x*=2)
		yenibasamak++ ;
		
	int sonuc=0;
	while(yenibasamak>0){
		x/=2;
    sonuc += (sayi/x)*pow(10,--yenibasamak);
    sayi%=x;           }
	
	return sonuc;
}	

int onluk(long int sayi){ //Onluk sisteme çevirm
	int basamak=0;
	int i=1;
	for(;i<=sayi;i*=10)
		basamak++;
	
	int sonuc=0;
	i/=10;
	while(i>0){
		sonuc+= (sayi/i)*pow(2,--basamak);
		sayi%=i;
		i/=10;    }
		
	return sonuc;
}

int main(){
	int a,b;
	char c;
	unsigned int ussayaci=0;
	unsigned long int sonuc=0;
	printf("Bit operatoru hesaplayicisi: ");
	scanf("%d%c%d",&a,&c,&b);
	
	a=cevirme(a);
	b=cevirme(b);
	
	while(a||b){
		switch(c){
			case '&': sonuc += ( (a%10)&&(b%10) )*pow(10,ussayaci); break;
			case '|': sonuc += ( (a%10)||(b%10) )*pow(10,ussayaci); break;
			case '^': sonuc += ( ( (a%10)||(b%10) )&&( !(a%10)||!(b%10) ) )*pow(10,ussayaci); break;
			
			case '>': for(b=onluk(b);b>0;b--)
						  a/=10;
					  printf("Sonuc: %d",onluk(a)); return 0;
			
			case '<': for(b=onluk(b);b>0;b--)
						  a*=10;
					  printf("Sonuc: %d",onluk(a)); return 0;		  	 }
					  
		a/=10;
		b/=10;
		ussayaci++;}
	printf("Sonuc: %d",onluk(sonuc));
	
}
