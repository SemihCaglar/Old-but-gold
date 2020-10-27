#include<stdio.h>
int main(){
    int n,i,girdi,buyuk,kucuk;
    float toplam=0;
    
    printf("Terim sayisini giriniz:");
    scanf("%d",&n);
    printf("\nTerimleri giriniz:");
    scanf("%d",&girdi);
    
    i=n;
    toplam+=girdi;
    buyuk=girdi;
    kucuk=girdi;
    
    while(i>1){
        scanf("%d",&girdi);
        toplam+=girdi;
        
        if(girdi>=buyuk)
            buyuk=girdi;
       
        if(girdi<=kucuk)
            kucuk=girdi;
        
        i--;              }
    
    printf("En buyugu: %d\nEn kucugu: %d\nOrtalama: %.2f",buyuk,kucuk,toplam/n);
    
}