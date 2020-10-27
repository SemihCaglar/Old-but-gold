#include<stdio.h>
int main(){
    int n,i,basamak,tekler,ciftler;
    printf("Sayi giriniz:");
    scanf("%d",&n);
    basamak=0;
    i=1;
    tekler=0;
    ciftler=0;
    
    while(i<=n){
       basamak+=1;
       i*=10;  }
    
    i/=10;
    
    while(basamak>0){
       ((n/i)%2==1)?tekler+=n/i:ciftler+=n/i;
       n%=i; 
       i/=10;
       basamak--;   }
    
    printf("\nTeklerin toplami:%d\nCiftlerin toplami:%d",tekler,ciftler);
    
}