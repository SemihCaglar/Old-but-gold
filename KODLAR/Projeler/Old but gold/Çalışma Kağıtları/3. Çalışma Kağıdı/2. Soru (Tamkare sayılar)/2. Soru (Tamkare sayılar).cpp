#include<stdio.h>
int main(){
    int x,n;
    printf("Sayi giriniz:");
    scanf("%d",&n);
    x=1;
    
    while(x*x<=n){
        printf("%d ",x*x);
        x++;     }
}