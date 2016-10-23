//
//  main.c
//  tax_27422
//
//  Created by Erica on 2016/8/19.
//  Copyright © 2016年 Erica. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int income, discount, taxpay;
    double taxrate, tax;
    
    scanf("%d", &income);
    
    if(income >=0 && income < 370000){
        discount = 0;
        taxrate = 0.06;
    }
    else if(income >= 370000   && income < 990000){
        discount = 25900;
        taxrate = 0.13;
    }
    else if(income >= 990000  && income < 1980000 ){
        discount = 105100;
        taxrate = 0.21;
    }
    else if(income >= 1980000  && income < 3720000 ){
        discount = 283300;
        taxrate = 0.30;
    }
    else{
        discount = 655300;
        taxrate = 0.40;
        
    }
    
    tax = income*taxrate;
    taxpay = (int)tax - discount;
    
    printf("income %d\n", income);
    printf("tax rate %.0f%%\n", taxrate*100);
    printf("tax %.0f\n", tax);
    printf("discount %d\n", discount);
    printf("taxpay %d\n", taxpay);
    
    return 0;
}
