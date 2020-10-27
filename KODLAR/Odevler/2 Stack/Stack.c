#include<stdio.h>

int s[100];
int p=-1;

void push(int x){
    s[++p]=x;
}

int pop(){
    if(p<0) 
        return -1;
    return s[p--];
}

int main(){
    // Ornek girdi:
    push(5);
    push(8);
    push(3);
    printf("%d ", pop());
    push(12);
    push(40);
    printf("%d ", pop());
    push(2);
    push(1);
    push(17);
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());
    printf("%d ", pop());

    // Ornek cikti: 3 40 17 1 2 12 8 5 -1
}