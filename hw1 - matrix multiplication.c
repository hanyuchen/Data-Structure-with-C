//
//  main.c
//  metrix_27422
//
//  Created by Erica on 2016/8/19.
//  Copyright © 2016年 Erica. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void input2dAry(int ary[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&ary[i][j]);
        }
        //printf("\n");
    }
}


void Print2dAry(int ary[][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%-5d",ary[i][j]);
        }
        printf("\n");
        
    }
}
void MatrixMul2dAry(int c[][3],int a[][3],int b[][3])
{
    int i,j,k;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[i][j]=0;
            for(k=0;k<3;k++)
            {
                c[i][j]+=a[i][k] * b[k][j];
            }
            printf("%-5d",c[i][j]);
        }
        printf("\n");
        
    }
}
int main(int argc, char *argv[]) {
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int b[3][3]={2,4,6,8,10,12,14,16,18};
    int c[3][3];
    //int i,j,k;
    
    //input2dAry(a);
    //input2dAry(b);
    /*for(i=0;i<3;i++)
     {
     for(j=0;j<3;j++)
     {
     c[i][j]=0;
     for(k=0;k<3;k++)
     {
     c[i][j]+=a[i][k] * b[k][j];
     }
     printf("%-5d",c[i][j]);
     
     }
     printf("\n");
     
     }*/
    
    MatrixMul2dAry(c,a,b);
    
    //Print2dAry(c) ;
    
    
    return 0;
}
