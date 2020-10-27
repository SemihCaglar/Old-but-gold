#include<stdio.h>
int main(){
    printf("Adim sayisini giriniz: ");
    int n;
    scanf("%d",&n);
    int i=2;
    int x,y,z;
    x=1;
    y=0;
    
    printf("\n0. Adım: 0\n");
    if(n>=1){
    printf("1. Adım: 1\n");}
    
    while(i<=n){
        z=x+y;
        y=x;
        x=z;
        printf("%d. Adım: %d\n",i,z);
        i++;
    }
}