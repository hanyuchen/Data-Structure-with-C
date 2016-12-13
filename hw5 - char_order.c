#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
 void swap(int *a, int*b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
 }
 */

void swap(char *a, char b[]){ //兩種寫法是一樣意思
    char temp[80];
    strcpy(temp, a);
    strcpy(a,b);
    strcpy(b,temp);
}


//void print(int n, int*p){
void print(int n, char p[][80]){
    
    int i;
    for(i=0; i<n; i++){
        printf("%s ", p[i]);
    }
    printf("\n");
}

int bsort(int n, char data[][80]){
    //int data[5] = {34,12,5,66,1}; // 欲排序的資料
    int i, j;
    //int n=5;
    for(i=n; i>1; i--){
        for(j=0; j<i-1; j++){
            //if(data[j+1] < data[j]){
            if(strcmp(data[j+1],data[j])>0)	{
                
                //swap(&data[j+1], &data[j]);
                swap(data[j+1], data[j]);
            }
        }
        print(n,data);
    }
    return 0;
}

int ssort(int n, char data[][80]){
    
    int i, j, pos;
    //int n=5;
    for(i=0; i<n-1; i++){
        pos = i;
        for(j=i+1; j<n; j++){
            if(strcmp(data[j],data[pos])>0)
                pos = j;
        }
        
        swap(data[i], data[pos]);
        print(n,data);
    }
    return 0;
}



int isort(int n, char data[][80]){
    //	int data[5] = {34,12,5,66,1}; //
    int i, j;
    char key[80];
    //	int n=5;
    for( i=1; i<n; i++){
        strcpy(key, data[i]);
        for(j=i-1; j>=0 && strcmp(data[j],key) <0 ; j--){
            strcpy(data[j+1], data[j]);
        }
        strcpy(data[j+1], key);
        print(n,data);
    }
    return 0;
}



int main(){
    
    char data[6][80]; //六個長度為80的字元陣列
    int n = 6;
    int i, sel;
    for(i=0;i<n;i++){
        scanf("%s", &data[i]);
    }
    
    scanf("%d", &sel);
    switch(sel){
        case 1:
            bsort(n,data);
            print(n,data);
            break;
        case 2:
            ssort(n,data);
            print(n,data);
            break;
        case 3:
            isort(n,data);
            print(n,data);
            break;
            
    }
    
    return 0;
    
}
