#include<stdio.h>
int altdeger;
int ustdeger;
int i;

void aralik(int x){
    i=1;
    while(i*i<x)
       i++;
    altdeger=(i-1)*(i-1);
    ustdeger=i*i;

}

int main(){
    int n;
    printf("Su sayinin karekokunun yaklasik değerini yazdırın: ");
    scanf("%d",&n);
    aralik(n);
    printf("\nYaklasik deger: %f",(i-1)+(n-altdeger)/float((ustdeger-altdeger)));
 
}