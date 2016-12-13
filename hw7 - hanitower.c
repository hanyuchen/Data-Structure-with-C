#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void hanoi (int n, char from, char mid, char to, int *ary){
    // 在搬動第n個圓盤時
    if(n==0)
        return ;
    // 先將第n-1個圓盤搬到 '中間塔'
    hanoi (n-1,from, to, mid, ary);
    // 將自己搬到 '目標塔'
    printf ("plate%2d from %c -> %c \n",n,from,to);
    ary[n-1]++;
    // 再將第n-1個圓盤從'中間塔' 搬回來
    hanoi (n-1,mid, from, to, ary);
    
}


int main(){
    int n,i, ct[50]={0};   //ct為計數器, 初始為0
    scanf("%d",&n);
    hanoi(n,'A','B','C',ct);
    puts("");
    for(i=0;i<n;i++){
        printf("plate %d = %d\n",i+1,ct[i]);
    }
    
}
