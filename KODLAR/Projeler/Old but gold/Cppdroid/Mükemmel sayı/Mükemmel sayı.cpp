#include<stdio.h>
int main(){
    int toplam,n;
    printf("Su sayiya kadarki mukemmel sayilari yazdir: ");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        toplam=0;
        for(int carpan=1;carpan<i;carpan++){
            if(!(i%carpan))
               toplam+=carpan;             }
        if(toplam==i)
           printf("\n%d",i);
    }

}