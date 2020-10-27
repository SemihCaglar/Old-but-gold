#include<stdio.h>
int main(){
    int kilo;
    int boy;
    int yas;
    float bazal;
  
    printf("Kilonuzu giriniz:");
    scanf("%d",&kilo);
    printf("Boyunuzu (cm) giriniz:");
    scanf("%d",&boy);
    printf("Yasinizi giriniz:");
    scanf("%d",&yas);
    
    bazal=655+9.6*kilo+1.8*boy-4.7*yas;
    printf("\nBazal metobolizma hizi:%.2f",bazal);
    
    
    
    
}