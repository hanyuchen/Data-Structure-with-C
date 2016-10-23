//
//  main.c
//  recursion
//
//  Created by Erica on 2016/8/19.
//  Copyright © 2016年 Erica. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

int numN, numM, ans;
int comb(numN, numM){

    if(numN == numM || numM == 0){
    
        return 1;
    
    }
    else{
    
        return comb(numN-1,numM) + comb(numN-1,numM-1);
    
    }
    

}

int main(){
    
    scanf("%d", &numN);
    scanf("%d", &numM);
    
    if(numN > numM){
    
        ans = comb(numN, numM);
        printf("%d\n", ans);
    
    }
    else{
        
        printf("input error");
    
    }
    
    system("PAUSE");
    return 0;
}
