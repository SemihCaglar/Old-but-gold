#include<stdio.h>
int main(){
    int x,y;
    printf("Sayilari giriniz:");
    scanf("%d%d",&x,&y);
    switch(x>y){
      case 1:printf("%d",x); break;
      case 0:(x==y)?printf("%d*",x):
      printf("%d",y); break;
    }
}