#include<stdio.h>
int n=5;
int cq[5];
int al=0,at=0;

void artir(int &x){
    x= x==n-1 ? 0 : x+1 ;
}

int pop(){
    int returnn;
    returnn=cq[at];
    if(returnn==-1)
        return -1;
    cq[at]=-1;
    artir(at);
    return returnn;
}

void push(int x){
    if(al==at) 
        pop();
    cq[al]=x;
    artir(al);
}

int main(){

    for(int i=0;i<n;++i)
        cq[i]=-1;
    
    // Ornek girdi:
    push(5);
    push(8);
    push(3);
    printf("%d ",pop());
    push(12);
    push(40);
    printf("%d ",pop());
    push(2);
    push(1);
    push(17);
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    printf("%d ",pop());
    getchar();

    // Ornek cikti: 5 8 12 40 2 1 17 -1
}