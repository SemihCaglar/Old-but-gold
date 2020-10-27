#include<stdio.h>
int main(){
    int x,y,z;
    printf("Ucgenin kenarları:");
    scanf("%d%d%d",&x,&y,&z);
    
    int mutlak1,mutlak2,mutlak3;
    (x>y)?mutlak1=x-y:mutlak1=y-x;
    (x>z)?mutlak2=x-z:mutlak2=z-x;
    (y>z)?mutlak3=y-z:mutlak3=z-y;   
    
    if((x<y+z)&&(y<x+z)&&(z<x+y)&&(x>mutlak3)&&(y>mutlak2)&&(z>mutlak1))
    printf("Ucgen cizilebilir.");
else
    printf("Ucgen Cizilemez.");

}