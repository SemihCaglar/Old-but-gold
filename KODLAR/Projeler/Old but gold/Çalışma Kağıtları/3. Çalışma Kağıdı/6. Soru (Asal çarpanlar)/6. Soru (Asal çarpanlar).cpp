#include<stdio.h>
int main(){
    int n,asal; //Asal olmak zorunda değil, bölen anlamında
    printf("Sayi giriniz:");
    scanf("%d",&n);
    asal=2;
    printf("\nAsal carpanlari:\n");
    
    while(n>1){
        while(n%asal==0){
            printf("%d\n",asal);
            n/=asal;    }
            asal++;     
    }
}