#include<iostream>
#include<stack>
using namespace std;

stack<int> at;
stack<int> al;

void push(int x){
    at.push(x);
}

int pop(){
    if(al.empty()){
        if(at.empty())
            return -1;
        while(!at.empty()){
            al.push(at.top());
            at.pop();
        }
    }
    int returnn=al.top();
    al.pop();
    return returnn;
}

int main(){
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
    // 5 8 3 12 40 2 1 17 -1
}