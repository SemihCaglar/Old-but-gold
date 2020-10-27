#include<stdio.h>
int main(){
	/* &&: ve
	   ||: veya
	   ==: eþit
	   !=: eþit deðil
	   if ( !(sayi&2) )
	      printf (çift)   */
	      
	/*    if durumu?yapýlacaklar:else yapýlacaklar 
	      a?b:c */  
	      
	char karakter;
	printf("Bir harf yaziniz:");
	scanf("%c",&karakter);
	
	if (karakter<='Z')
		printf("\nBuyuk harf\n");
		
	else
		printf("\nKucuk harf\n");
	
	if((karakter=='F')||(karakter=='f'))
		printf("Hey!");	
	
	
	
}
