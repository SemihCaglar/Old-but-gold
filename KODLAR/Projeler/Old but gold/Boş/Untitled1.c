#include<stdio.h>

int main(){
	int ar[]={{5,9},{12,3},{8,1},{3,4}},i=0,s=0;
	for(i=0;i<4;i+=3)
		printf("%d ",ar[i]);
	printf("%d",s);
}
