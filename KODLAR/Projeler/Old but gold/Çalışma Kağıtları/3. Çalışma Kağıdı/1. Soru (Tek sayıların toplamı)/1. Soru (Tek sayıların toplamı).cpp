#include<stdio.h>
int main(){
    int n,sonuc;
    printf("Sayi giriniz:");
    scanf("%d",&n);
    sonuc=0;
   
    if(n%2==0)
       n-=1;
    
    while(n>=1){
       sonuc+=n;
       n-=2;   }
    
    printf("%d",sonuc);
 
}