#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Return deðerleri: önceyse 1, sonraysa 2.

int lexicographic_sort(const char* a, const char* b) {
    char*aa=(char*)malloc(strlen(a)+1);
	char*bb=(char*)malloc(strlen(b)+1);
	strcpy(aa,a);
	strcpy(bb,b);
	int i=0;
    while(1){
        if(*(aa+i)==*(bb+i)){
			i++;
            continue; }
        return *(aa+i)<*(bb+i)?1:2;
		break;    
    }    
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return lexicographic_sort(b,a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    char *ara=(char*)malloc(strlen(a)+1);
    char *arb=(char*)malloc(strlen(b)+1);
    int xa=0,xb=0;
    bool h;

    for(int i=0;i<strlen(a);i++){
        h=true;
        for(int j=0;j<xa;j++){
            if( *(a+i) == *(ara+j) )
                h=false;     }
        if(h)
            xa++;
    }
    
    for(int i=0;i<strlen(b);i++){
        h=true;
        for(int j=0;j<xb;j++){
            if( *(b+i) == *(arb+j) )
                h=false;     }
        if(h)
            xb++;
    }
    return xa<xb?1:xa>xb?2:lexicographic_sort(a,b);
    
}

int sort_by_length(const char* a, const char* b) {
    return strlen(a)<strlen(b)?1:strlen(a)>strlen(b)?2:lexicographic_sort(a,b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char *tmp=(char*)malloc(1);
	for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            printf("hsshsjsx");
			if(cmp_func(arr[i],arr[j])==2){
                tmp=(char*)realloc(tmp, strlen(arr[i])>strlen(arr[j])?strlen(arr[i])+1:strlen(arr[j])+1 );
				strcpy(tmp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],tmp);
            }
        }
    }
}



int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    int (*fptr[4])(const char*,const char*)={lexicographic_sort,lexicographic_sort_reverse,sort_by_length,sort_by_number_of_distinct_characters};
    printf("\n");
    for(int i=0;i<4;i++){
    	string_sort(arr, n, fptr[i]);
    	for(int i = 0; i < n; i++)
        	printf("%s\n", arr[i]);
		printf("\n");
	}
    
/*	string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
	printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
  */  
}
