#include<stdio.h>
int main(){
    
    int kenar;
    int yukseklik;
    float alan;
    printf("Ucgenin bir kenarinin uzunlugunu giriniz:");
    scanf("%d",&kenar);
    printf("Bu kenara ait yüksekliğin uzunluğunu giriniz:");
    scanf("%d",&yukseklik);
    
    alan=kenar*yukseklik/2.0;
    printf("\nUcgenin alanı:%.1f cm ",alan);
    
    
    
}