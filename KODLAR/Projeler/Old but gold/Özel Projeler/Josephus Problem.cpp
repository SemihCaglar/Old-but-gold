#include<stdio.h>

int artibir(int n,int semih){
	return n==semih-1?0:n+1; }
	
int main(){
	int n,semih,hikmet=1,a=0; //a: öldürülen sayýsý   Hikmet: survivor
	printf("How many brave guys are there? ");
	scanf("%d",&n);
	
	if(n<1){
		printf("Wtf?");
		return 0;}
		
	semih=n;
	int ar[n];
	for(;n>0;n--)
		ar[n-1]=n;
		
	printf("\n");
	
	while(a!=semih-1){
		while(ar[n]==0)
			n=artibir(n,semih);
		hikmet=ar[n];	
		printf("%d ",ar[n]);	
		n=artibir(n,semih);
		while(ar[n]==0)
			n=artibir(n,semih); 
		printf("killed %d\n",ar[n]);	
		ar[n]=0;
		a++;
	}
	printf("\nJosephus (Survivor) is %d.\n\n",hikmet);
	printf("\nThe most handsome people in the world (Semih and Hikmet) wrote this code...\n                                                                            Good game...");
}
