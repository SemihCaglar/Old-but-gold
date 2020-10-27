#include<stdio.h>

int usalma(int kuvvet){
    int carpan=1;
    for(int i=0;i<kuvvet;i++){
        carpan*=10;          }
        return carpan;        
}

int bolen(int x,int y){ //x:sayı  y:basamak
    int sonrakam=x%10;
    int ilkrakam=x/usalma(y-1);
    return ilkrakam*10+sonrakam;
}

int main(){
    int basamak,n;
    printf("Gapful sayisi ilk ve son rakaminin birlesimine bolunebilen sayidir.\nKac basamakli gapful sayilarini yazdiralim? ");
    scanf("%d",&n);
    
    for(int i=usalma(n-1);i<usalma(n);i++){
        basamak=0;
        for(int a=1;a<=i;a*=10){
            basamak++;         }
        if(!(i % bolen(i,basamak)))
          printf("\n%d",i);
    }

}


