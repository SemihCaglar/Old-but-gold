#include<stdio.h>
#define ulli unsigned long long int

ulli asal[999999]={2,3};

int main(){
ulli i=2,semih,bolen;

printf("2 3 ");

for(ulli a=5;a<999999999999999999;a+=2){
	semih=0;
	bolen=0;
	for(ulli x=0;x<i;x++){
		if(a%asal[semih]==0){
		bolen++; 
		break;  } 
		
		semih++;
	}
	
	if(bolen==0){
		asal[i]=a;
		i++;
		printf("%d ",a);
	}
	
}

}
