#include<stdio.h>
int main(){
    int kilo;
    int boy;
    float vki;
  
    printf("Kilonuzu giriniz:");
    scanf("%d",&kilo);
    printf("Boyunuzu (cm) giriniz:");
    scanf("%d",&boy);
    
    vki=kilo/(boy*boy/10000.0);
    printf("\nVücut Kitle İndeksi:%.2f",vki);
    
}