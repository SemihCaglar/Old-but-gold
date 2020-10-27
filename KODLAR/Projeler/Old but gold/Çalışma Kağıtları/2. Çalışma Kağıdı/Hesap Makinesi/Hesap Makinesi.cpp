#include<stdio.h>
int main (){
    float x,y;
    char z;
    printf("Hesap makinesi: ");
    scanf("%f%c%f",&x,&z,&y);
    printf("%.1f%c%.1f=",x,z,y);
    
    switch(z){
    case '+': printf("%.2f",x+y); break;
    case '-': printf("%.2f",x-y); break;
    case '*': printf("%.2f",x*y); break;
    case '/': printf("%f",x/y); break;
    case '%': printf("%d",(int)x%(int)y);               
              break;
    }
}