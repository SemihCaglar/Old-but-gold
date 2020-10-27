#include<stdio.h>
#include<cstdlib>
#include<cmath>

char *str;

class Polinom{   // Hepsini ayn� tarafta tutuyor. ...=0 
	
	public:
		
		Polinom(){
			derece= -1;
			katsayi=(double*)malloc(sizeof(double));
			katsayi[0]=0;
		}
		~Polinom(){
			katsayi=(double*)realloc(katsayi,0);
		}
		
		void yazdir(){ //ge�ici
			for(int i=derece;i>=0;i--){
				printf("%.0f",katsayi[i]);
				if(i>0)printf("x");
				if(i>1) printf("^%d",i);
				printf("\n");
			}
			printf("=0\n\n");
		}
		
		void ekle(double katsayi,int derece){
			if(derece>this->derece){
				this->katsayi=(double*)realloc(this->katsayi,(derece+1)*sizeof(double));
				for(int i=this->derece+1;i<derece;i++)
					this->katsayi[i]=0;
				this->derece=derece;
				this->katsayi[derece]=0;
			}
			this->katsayi[derece]+=katsayi;
		}
		
		Polinom operator*(Polinom&obj){
			Polinom res;
			for(int i=0;i<=this->derece;i++)
				for(int j=0;j<=obj.derece;j++)
					res.ekle( this->katsayi[i] * obj.katsayi[j] , i+j );
			return res;	
		}
		
		Polinom operator~(){     // T�revini al�yor.
			Polinom res;
			for(int i=1;i<=this->derece;i++)
				res.ekle(this->katsayi[i]*i,i-1);
			return res;
		}
		
		double operator+(double &x){
			double sum=0.0;
			double carpan=1.0;
			for(int i=0;i<=this->derece;i++,carpan*=x){
				sum+= this->katsayi[i]*carpan;        }
			return sum;	 	
		}
	
	private:
		
		int derece;
		double *katsayi;
		
		friend void set(Polinom &semih);
		friend double kokbul(Polinom &semih,double bas,double son,bool &durum);
		friend double*kokler(Polinom &semih,int &bulunan);
};

/*_____________________________________________________________________________________*/

double sayi(char*ar,int &i){
	int us=0;
	double returnn=0.0;
	for(;i>=0&&ar[i]<='9'&&ar[i]>='0';--i)
		returnn+=(ar[i]-'0')*pow(10,us++);
	
	semih:	
	switch(ar[i]){
		case '.':returnn/=pow(10,us);
				 for(--i,us=0;ar[i]<='9'&&ar[i]>='0';--i)
				 	returnn+=(ar[i]-'0')*pow(10,us++);
				 goto semih;
		case '-':returnn*=-1;		 
	}
	return returnn;
}

void set(Polinom &semih){
	
	bool h=false; // x ��k�nca true.
	int taraf=1,derece=0;
	double girdi;
	const char bilinmeyen='x';
		
	str=(char*)malloc(100);
	fgets(str,100,stdin);
	int len=0;
	for(int i=0;str[i]!='\0';i=++len);
	--len;
	str=(char*)realloc(str,len);
	
	for(--len;len>=0;--len){
		
		if(str[len]>='0'&&str[len]<='9')
			girdi=sayi(str,len);	
		else if(h==true)
			girdi=str[len]=='-' ? -1 : 1;
		if(len<0) break;
		
		switch(str[len]){
			case '-':
			case '+': semih.ekle(girdi*taraf,derece); h=false; derece=0; break;
			case '^': derece=(int)girdi; break;
			case '=': semih.ekle(girdi*taraf,derece); h=false; derece=0; taraf=-1; break;
			case bilinmeyen: h=true; derece=derece==0?1:derece; break;					
		}
	}
	
	if(str[0]==bilinmeyen)
		girdi=1;
	semih.ekle(girdi*taraf,derece);
	free(str);
}

/*_____________________________________________________________________________________*/

double kokbul(Polinom &semih,double bas,double son,bool &durum){
	
	double temp,j;
	short sign,onceki;
	durum=false;
	
	theschool:                                                                  	                                                                                
	temp=semih+bas;                                                                        
	sign= temp<=1e-10&&temp>=-1e-10 ? 0 : temp>0 ? 1: -1;         
	for(int i=0;i<3;i++){                                                                                                                                                
		if(i==0) j=bas;                                                                    
		else if(i==1) j=(son+bas)/2;                                                       
		else j=son;                                                                        
		temp=semih+j;                                                                      
                                  
		if(temp<=1e-10&&temp>=-1e-10){        
			durum=true;
			return j;                                                                                                                                       
		}                                                                                  
		                                                                                   
		short onceki=sign;																   
		sign= temp<=1e-10&&temp>=-1e-10 ? 0 : temp>0 ? 1: -1;     
																						   
		if(sign==-1&&onceki==1 || sign==1&&onceki==-1){                                                                    
			bas= j-(son-bas)/2;                                                            
			son=j;																		   
			goto theschool;                                                                    
		}                                                                                  
 		                                                                                   
	}
	
	return 0.0;             
	
}

double*kokler(Polinom &semih,int &bulunan){
	
	double*ptr;
	ptr=(double*)malloc(0);
	
	if(semih.derece==1){
		ptr=(double*)malloc(1*sizeof(double));
		ptr[0]=semih.katsayi[0] * -1 / semih.katsayi[1];
		bulunan=1;
		return ptr;
	}

	double bas,son,*yondegis;
	bool durum;
	int k;
	
	{Polinom serdar= ~semih;
	yondegis=kokler(serdar,k);}
	bulunan=0;
	
	bas= -100;
	son=yondegis[0];
	bas=kokbul(semih,bas,son,durum); 
	if(durum&&ptr[bulunan-1]!=bas){ 
		ptr=(double*)realloc(ptr,++bulunan*sizeof(double)); 
		ptr[bulunan-1]=bas; 
	}
	
	for(int a=0;a<k-1;a++){		
		bas=yondegis[a];
		son=yondegis[a+1];
		bas=kokbul(semih,bas,son,durum); 
		if(durum&&ptr[bulunan-1]!=bas){ 
			ptr=(double*)realloc(ptr,++bulunan*sizeof(double)); 
			ptr[bulunan-1]=bas; 
		}
	}
	
	bas= yondegis[k-1];
	son= 100;
	free(yondegis);
	bas=kokbul(semih,bas,son,durum); 
	if(durum&&ptr[bulunan-1]!=bas){ 
		ptr=(double*)realloc(ptr,++bulunan*sizeof(double)); 
		ptr[bulunan-1]=bas; 
	}
		
	return ptr;

}

int main(){
	
	Polinom semih;
	set(semih);
	int sayi;
	double *p=kokler(semih,sayi);
	printf("\nDenklemin reel sayilardaki kokleri:\n{");
	for(int i=0;i<sayi;i++)
		printf("  %c  %f", i?',':NULL , p[i]);	
	free(p);
	printf("     }\n\nSemih Caglar tarafindan yapildi.\n");
	getchar();

}
