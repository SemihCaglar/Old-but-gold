#include<stdio.h>
int main(){
    int x,n,sonuc;
    printf("Sayi giriniz:");
    scanf("%d",&n);
    x=1;
    sonuc=1;
    
    while(x<=n+1){
        printf("%d ",sonuc);
        sonuc*=2;
        x++;
    }

}