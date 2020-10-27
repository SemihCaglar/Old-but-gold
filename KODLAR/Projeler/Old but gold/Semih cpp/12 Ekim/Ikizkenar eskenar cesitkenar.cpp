#include<stdio.h>
int main(){
	int x,y,z;
	printf("Ucgenin uzunluklarýný giriniz: ");
	scanf("%d%d%d",&x,&y,&z);
	
	if ((x==y)&&(x==z))
    	printf("\nEskenar ucgen");
    	
	else if ((x!=y)&&(x!=z)&&(y!=z))
		printf ("\nCesitkenar ucgen");
		
		else
			printf("\nIkizkenar ucgen");
	
	
}
