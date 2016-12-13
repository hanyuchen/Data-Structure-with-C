#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print(int n, char p[][128]){
    int i;
    for(i=0; i<n; i++){
        printf("%s ", p[i]);
    }
    printf("\n");
}

int LinearSearch(int n, char p[][128], char value[128]){ //p是陣列名稱
    int i;
    for(i=0; i< n; i++){
        printf("%d: %s\n",i,p[i]);
        if(strcmp(p[i], value) == 0){
            return i; // 找到: 傳回資料位置
        }
    }
    return -1; // 找不到: 回傳-1
}

int BinarySearch(int n, char p[][128], char value[128]){
    int low=0, high=n, mid;
    while(low <= high){
        
        mid = (low + high) / 2;
        printf("%d: %s\n",mid,p[mid]);
        if(strcmp(p[mid], value)>0)
            high = mid -1;
        else if(strcmp(p[mid],value)<0)
            low = mid+1;
        else
            return mid;
    }
    return -1;
}


int main() {
    
    int sel, i, j;
    int n=0; // 目前已輸入的筆數資料
    char ary[10][128];
    char key[128];
    char value[128];
    int pos;
    
    while(1){
        /*	puts("1 insert");
         puts("2 linear search");
         puts("3 binary search");
         puts("4 print");
         puts("5 quit");
         */
        
     scanf("%d", &sel);
        
        switch(sel){
                
            case 1:
                scanf("%s ", &key);
                if(n==0){
                    strcpy(ary[0],key);
                }
                else{
                    //key=data[i];
                    for(j=n-1; j>=0 && strcmp(ary[j],key)>0; j--) {
                        strcpy(ary[j+1] , ary[j]);
                    }
                    strcpy(ary[j+1], key); //將key插入
                }
                n++;
                break;
                
            case 2:
                //printf("請輸入要找的字");
                scanf("%s", &value);
                //	int pos = LinearSearch(n,ary, value);  switch case裡面不能宣告變數所以不能這樣寫
                pos = LinearSearch(n,ary, value);
                if(pos == -1){
                    puts("not found");
                }
                else{
                    printf("found: %s\n", ary[pos]);
                    
                }
                
                break;
                
            case 3:
                //	printf("請輸入要找的字");
                scanf("%s", &value);
                //	int pos = LinearSearch(n,ary, value);  switch case裡面不能宣告變數所以不能這樣寫
                pos = BinarySearch(n,ary, value);
                if(pos==-1){
                    puts("not found");
                } else{
                    printf("found: %s\n", ary[pos]);
                    
                }
                break;
            case 4:
                print(n,ary);
                break;
            case 5:
                return 0;
                break;
                
        }
        //system("pause");
        //system("cls");
    }
    
    return 0;
}


