// Manyak Denklem Çözücüüü

#include<stdio.h>
#include<math.h>
#define n(x) (x-'1'+1)
#define D if(h==true){x+=girdi*f;h=false;}else{s+=girdi*f*-1;}
#define K if(k||ar[i]=='('){carpan=1.0;k=true;}
#define semih printf("   ---->SEMİH<----")

float sayi(char*ar,int*i){
	int us=0,bolunen;
	float Return=0.0;
	for( ; *i>=0 && ar[*i]>='0' && ar[*i]<='9' ; (*i)--)
		Return+=n(ar[*i]) * pow(10,us++);
	
	switch(ar[*i]){
		case '.':Return/=pow(10,us);
				 for((*i)--,us=0 ; *i>=0 && ar[*i]>='0' && ar[*i]<='9' ; (*i)--)
					 Return+=n(ar[*i]) * pow(10,us++);
				 break;	 
		
		case '-':Return*=-1; break;		 
	}
	
	return Return;
}

float carpann(char*ar,int i){
	for(;ar[i]!='(';i--);
	i--;
	if(ar[i]>='0'&&ar[i]<='9')
		return sayi(ar,&i);
	else
		return (i<0) ? 1.0 : ar[i]=='-' ? -1.0 : 1.0;		       
}

int main(){
	char ar[50],bilinmeyen;
	int i,f=1;
	bool h=false,k=true; //h:katsayı ise True, sabit terimse False   k:'/' ve ')' aynı anda olduğunda false
	float girdi,x=0.0,s=0.0,carpan=1.0;   //x: katsayı  s:sabit terim  carpan:parantez olduğu durumlarda
	
	fgets(ar,50,stdin);
	printf("\n\nEquation: "); puts(ar);
	for(i=0;ar[i]!='\0';i++);
	
	for(i-=2;i>=0;i--){
		
		if(ar[i]>='0'&&ar[i]<='9'){
			girdi=sayi(ar,&i)*carpan; K }
		else if(h==true){
			girdi=ar[i]=='-'?-1*carpan:1*carpan; K } 	
		if(i<0)
			break;
			
		switch(ar[i]){
			case '-':
			case '+':D break;
			case '/':carpan*=1/girdi; break;
			case '=':D f=-1; break;
			case ')':carpan*=carpann(ar,i); k=false; break;
			case '(':D i--; carpan=sayi(ar,&i); carpan=1.0;girdi=0.0; break;
			default:bilinmeyen=ar[i]; h=true; break;		 	}
	}
	if(ar[0]==bilinmeyen)
		girdi=1*carpan;
	D
	
	if(x==0&&s==0){
		printf("%c=R",bilinmeyen);
		semih;
		return 0; }
	if(x==0){
		printf("%c={ }",bilinmeyen);
		semih;
		return 0; }	
		
	if(x<0){
		x*=-1;
		s*=-1; }
	printf("%c= %.3f/%.3f = %.3f",bilinmeyen,s,x,s/x);
	semih;
	return 0;
}
