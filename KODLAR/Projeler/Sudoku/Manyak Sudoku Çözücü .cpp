// Manyak Sudoku ��z�c�����

#define dosya "myfile6.txt"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

short n;
short gereken=0;
short **sudoku;
struct olasi **ar;
struct olasi *satir,*sutun;
struct olasi **kare;
bool durum;

struct olasi{
	short sayi;
	short *arr;
};

bool icindemi(struct olasi *semih,short x){
	for(short i=0;i<semih->sayi;i++)
		if( *(semih->arr+i)==x )
			return 1;
	return 0;		
}

void cikar(struct olasi *arr,short x){
	for(short i=0;i<arr->sayi;i++)
		if( *(arr->arr+i)==x ){
			*(arr->arr+i)=*(arr->arr+arr->sayi-1);
			arr->arr=(short*)realloc( arr->arr,--(arr->sayi)*sizeof(short) );
			return;
		}
}

void hallet(short i,short j){
	
	ar[i][j].sayi= -1;
	ar[i][j].arr=(short*)realloc(ar[i][j].arr,0);
	gereken--;
	durum=true;
	
	for(short a=0;a<n*n;a++)
		if(!sudoku[i][a])
			cikar(ar[i]+a,sudoku[i][j]);
			
	for(short a=0;a<n*n;a++)
		if(!sudoku[a][j])
			cikar(ar[a]+j,sudoku[i][j]);
	
	for( short a=(i/n)*n;a<(i/n+1)*n;a++ )
		for( short b=(j/n)*n;b<(j/n+1)*n;b++ )
			if(!sudoku[a][b])
				cikar(ar[a]+b,sudoku[i][j]);
						
	cikar(satir+i,sudoku[i][j]);
	
	cikar(sutun+j,sudoku[i][j]);
	
	cikar(&kare[i/n][j/n],sudoku[i][j]);
}

/*__________________________________________________________________________________________________________________*/

void baslat(){
	
	ar=(struct olasi**)malloc(n*n*sizeof(struct olasi*));
	for(short i=0;i<n*n;i++)
		ar[i]=(struct olasi*)malloc(n*n*sizeof(struct olasi));
		
	kare=(struct olasi**)malloc(n*sizeof(struct olasi*));
	for(short i=0;i<n;i++)
		kare[i]=(struct olasi*)malloc(n*sizeof(struct olasi));
	
	satir=(struct olasi*)malloc(n*n*sizeof(struct olasi));
	sutun=(struct olasi*)malloc(n*n*sizeof(struct olasi));
	
	for(short i=0;i<n*n;i++)
		for(short j=0;j<n*n;j++){
			if(sudoku[i][j]==0){
				ar[i][j].sayi=n*n;
				ar[i][j].arr=(short*)malloc(ar[i][j].sayi*sizeof(short));
				for(short a=1;a<=n*n;a++)
					*(ar[i][j].arr+a-1)=a;
			}
			else{
				ar[i][j].sayi=0;
				ar[i][j].arr=(short*)malloc(0);   
			}
		}
		
	for(short i=0;i<n*n;i++){
		satir[i].sayi=n*n;
		satir[i].arr=(short*)malloc(satir[i].sayi*sizeof(short));
		for(short a=1;a<=n*n;a++)
			*(satir[i].arr+a-1)=a;
		sutun[i].sayi=n*n;
		sutun[i].arr=(short*)malloc(sutun[i].sayi*sizeof(short) );
		for(short b=1;b<=n*n;b++)
			*(sutun[i].arr+b-1)=b;	
	}

	for(short i=0;i<n;i++)
		for(short j=0;j<n;j++){
			kare[i][j].sayi=n*n;
			kare[i][j].arr=(short*)malloc(kare[i][j].sayi*sizeof(short));
			for(short a=1;a<=n*n;a++)
				*(kare[i][j].arr+a-1)=a;
		}

	for(short i=0;i<n*n;i++)
		for(short j=0;j<n*n;j++)
			if(sudoku[i][j]){
				hallet(i,j);
				gereken++;
			}
	durum=true;
}

void taktik1(){
	for(short i=0;i<n*n;i++)
		for(short j=0;j<n*n;j++)
			if(sudoku[i][j]==0 && ar[i][j].sayi==1){
				sudoku[i][j]= *(ar[i][j].arr);
				hallet(i,j);                       
			}  
	return;
}

void taktik2(){
	
	for(short i=0;i<n*n;i++){
		
		struct semih{
			short sayi;
			short konum;
		};
		struct semih array[satir[i].sayi];
		for(short a=0;a<satir[i].sayi;a++){
			array[a].sayi=*(satir[i].arr+a);
			array[a].konum= -1;
		}
		for(short j=0;j<n*n;j++)
			if(sudoku[i][j]==0)
				for(short a=0;a<satir[i].sayi;a++)
					if( icindemi( &ar[i][j] , array[a].sayi ) )
						array[a].konum= array[a].konum== -1 ? j : -5 ;
		
		for(short a=0,b=satir[i].sayi;a<b;a++)
			if(array[a].konum>=0 && sudoku[i][ array[a].konum ] == 0 ){
				sudoku[i][ array[a].konum ]= array[a].sayi;
				hallet(i,array[a].konum);
			}   
	}
		
	for(short i=0;i<n*n;i++){
		struct semih{
			short sayi;
			short konum;
		};
		struct semih array[sutun[i].sayi];
		for(short a=0;a<sutun[i].sayi;a++){
			array[a].sayi=*(sutun[i].arr+a);
			array[a].konum= -1;		
		}
		for(short j=0;j<n*n;j++)
			if(sudoku[j][i]==0)
				for(short a=0;a<sutun[i].sayi;a++)
					if( icindemi( &ar[j][i] , array[a].sayi ) )
						array[a].konum= array[a].konum== -1 ? j : -5 ;
			
		for(short a=0,b=sutun[i].sayi;a<b;a++)
			if(array[a].konum>=0 && sudoku[ array[a].konum ][i]== 0 ){
				sudoku[ array[a].konum ][i]= array[a].sayi;
				hallet(array[a].konum,i);
			}
	}    
	
	return;
}

void taktik3(){
	
	for(short i=0;i<n;i++)
		for(short j=0;j<n;j++){
			
			struct semih{
				short sayi;
				short x;
				short y;
			};
			struct semih array[ kare[i][j].sayi ];
			for(short a=0;a<kare[i][j].sayi;a++){
				array[a].sayi= *(kare[i][j].arr+a);
				array[a].x= -1;
				array[a].y= -1;
			}
			for(short a=i*n;a<i*n+n;a++)
				for(short b=j*n;b<j*n+n;b++)
					if(sudoku[a][b]==0)
						for(short x=0;x<kare[i][j].sayi;x++)
							if( icindemi( &ar[a][b] , array[x].sayi ) ){
								array[x].x= array[x].x== -1 ? a : -5 ;
								array[x].y= array[x].y== -1 ? b : -5 ;
							}				
			for(short a=0,b=kare[i][j].sayi;a<b;a++)
				if(array[a].x>=0 && sudoku[ array[a].x ][ array[a].y ] == 0){
					sudoku[ array[a].x ][ array[a].y ] = array[a].sayi;
					hallet( array[a].x , array[a].y );			
				}			
					
		}
	
	return;	
}

void sudokucoz(){
	
	baslat();
				
	while(gereken&&durum){
		durum=false;
		taktik1();
		taktik2();
		taktik3();
	} 
	return; 
}

int main(){
	
	//system("color E3");
	printf("Sudokunun kenar uzunlugu? ");
	scanf("%d",&n);
	n=sqrt(n);
	sudoku=(short**)malloc(n*n*sizeof(short*));
	for(short i=0;i<n*n;i++)
		sudoku[i]=(short*)malloc(n*n*sizeof(short));	
	
	FILE *in;
	in=fopen(dosya,"r");
	for(short i=0;i<n*n;i++)
		for(short j=0;j<n*n;j++){
			short a;
			fscanf(in,"%d",&a);	
			sudoku[i][j]=a;
			if(a==0)
				gereken++;
		}
	fclose(in);	
	
	sudokucoz();		
	
	FILE *out;
	out=fopen("Output.txt","w");
	if(out==NULL) printf("Sikinti\n");
	for(short i=0;i<n*n;i++){
		for(short j=0;j<n*n;j++)
			fprintf(out,"%d  ",sudoku[i][j]);
		fprintf(out,"\n\n");
	}
	fclose(out);
	
	printf(gereken?"\nAbim bu kadar yapabildim kusura bakma artik :)\n":"\nEzzzzzzzzzzzzzzzzzzzzzzz :)\n");
	getchar();
}				
