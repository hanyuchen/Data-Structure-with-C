//
//  main.c
//  reverse linked list
//
//  Created by Erica on 2016/8/27.
//  Copyright © 2016年 Erica. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>


struct LkLst{
    int data;
    struct LkLst*next;
};

typedef struct LkLst node;


int main() {
    
    node *head, *ptr;
    head = NULL; // important
    int input;
    
    while(1){
        
        scanf("%d", &input);
        if(input == -1)
            break;
        
        if(head==NULL){
            head = (node*)malloc(sizeof(node));
            head->next = NULL;
        }
        else{
            head = (node*)malloc(sizeof(node));
            head->next = ptr;
            
        }
        head->data = input;
        ptr = head;
    }
    
    ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    //free
    ptr = head;
    node *tmp;
    while(ptr!=NULL){
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
    
    
    
    return 0;
}
