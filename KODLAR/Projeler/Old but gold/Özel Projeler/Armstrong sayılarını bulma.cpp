#include<stdio.h>
int main(){
    int n,x,y,basamak,toplam,rakam,us;
    printf("Su sayiya kadarki armstrong sayilarini yaz: ");
	scanf("%d",&n);             
    for(int i=1;i<=n;i++){
        basamak=0;
        
        for(x=1;x<=i;x*=10){
            basamak++;     }
              
        toplam=0;
        y=i;
        
		for(int a=0;a<basamak;a++){
            x/=10;
            rakam=y/x;
            y%=x;
            us=1;
            
			for(int b=0;b<=basamak-1;b++){
                us*=rakam;               }  
            
            toplam+=us;
        }
        
		if(toplam==i)
           printf("\n%d",i);
    }

}
