// Telefon Rehberii

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct isim{
  char*ad;
  int sayi;
  char **ar;
};

isim *arr=(isim*)malloc(sizeof(isim));

int main(){
   int j=0,i=0;
   bool f=false;
   char *buffer;
   printf("Rehbere hosgeldiniz.\nKaydetmek istediginiz kisinin adini ve bir bosluk birakarak numarasini yaziniz.\n\"Bitir\" yazinca tum isimler alfabetik olarak listelenecektir.\n\n"); 
    
   while (true){
     buffer=(char*)malloc(15);
     scanf("%s",buffer);
     if (strcmp(buffer,"Bitir")==0) break;
     i=j;
     arr=(isim*)realloc(arr,sizeof(isim)*(i+1) );
     
     for(int a=0;a<j;a++)
      if( strcmp(buffer,arr[a].ad)==0 ){
        i=a;
        j--;
        f=true;
        break;                         } 
     j++;
	 if(!f){
	 	arr[i].sayi=0;   
        arr[i].ar=(char**)malloc(sizeof(char*)); }
		  
     arr[i].sayi++;
     arr[i].ad=(char*)malloc(strlen(buffer)+1);
     arr[i].ar=(char**)realloc(arr[i].ar,sizeof(char*)*arr[i].sayi);
     arr[i].ar[arr[i].sayi-1]=(char*)malloc(15);
     strcpy(arr[i].ad,buffer);
     free(buffer);
     scanf("%s",arr[i].ar[arr[i].sayi-1]);
     arr[i].ar[arr[i].sayi-1]=(char*)realloc(arr[i].ar[arr[i].sayi-1],strlen(arr[i].ar[arr[i].sayi-1])+1);
   
   	 f=false;
   }
   
	free(buffer);
	int semih,c;
	printf("\n"); 
   
	for(int b=0;b<j;b++){
  		c=0;
  		for(;!arr[c].sayi;c++);
  		semih=c;
  
  		for(;c<j;c++)
  			if( arr[c].sayi && strcmp(arr[semih].ad,arr[c].ad)>0 )
  				semih=c;
				
	  	if(arr[semih].sayi!=1)
    		for(int q=0;q<arr[semih].sayi;q++)
      			printf("%s(%d) %s\n",arr[semih].ad,q+1,arr[semih].ar[semih]);
  		else 
    		printf("%s %s\n",arr[semih].ad,arr[semih].ar[0]);
    
  		arr[semih].sayi=0;  
	} 

}
