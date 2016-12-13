#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
    int data;
    struct _node *next;
};
typedef struct node node;

node *getnode () /* 此函數產生一個新節點 */ {
    node *p;
    p = (node *) malloc(sizeof(node));
    /* malloc 會動態地配置大小為sizeof 的記憶體*/
    /* sizeof 會傳回一個型態為node之值*/
    
    if ( p == NULL)
    {
        printf ("記憶體不足");
        exit(1);
    }
    return(p);

}

void freenode (node *p){
    free(p);
}

node *insert_node (node *head, node *ptr, node data) {
    
    node *new_node;   /* 新節點指標變數 */
    new_node = getnode(); /* 建立新節點,取得一個可用節點 */
    *new_node = data; /* 建立節點內容 */
    new_node->next = NULL; /* 設定指標初值 */
    if ( ptr == NULL ) /* 指標ptr是否是NULL */{
        new_node->next = head;
        head = new_node;
        
    }
    else {
        if ( ptr->next == NULL ) /* 是否是串列結束 */
    /* 第二種情況: 插入最後一個節點 */
            ptr->next = new_node;
        else{
            new_node->next=ptr->next;
            ptr->next = new_node;
        }
    }
    return (head);
}


node *insert_first(node *head, node *ptr, node data){
        node *new_node;
        new_node = getnode();
        *new_node = data;
        new_node->next = NULL;
        
        if ( ptr == NULL ){
            new_node->next = head;
            head = new_node;
        }
        else
        {
            if ( ptr->next == NULL )
                ptr->next = new_node;
            else
            {
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
        }
        return (head);
}

int prime(int n){
    int Ft=0;
    int i;
    for(i=2;i<n;i++){
        if(n%i==0)
        {
            Ft=1;
            
            break;
        }
    }
    return Ft;
}



int main(){
    
    char sel;
    int n;
    node *head,*head_first, *ptr,*pt;
    
    node factor;
    
    //prime
    
    
    while(1){
        
        puts("1 輸入要判斷的數");
        puts("2 列出所有因數");
        puts("3 判斷質數");
        puts("4 順序印出");
        puts("5 反序印出");
        puts("6 離開");
        
        scanf(" %c", &sel);
        switch(sel)
        {
            case '1':
                scanf("%d",&n);
                ptr=NULL;
                break;
                
            case '2':
                factor.data = 1;
                head = NULL;
                head_first = NULL;
                while( factor.data <= n ){
                    if( n%factor.data == 0 ){
                        printf("%d ",factor.data);
                        if(head == NULL){
                            head = insert_node (head, NULL, factor);
                        }
                        else{
                            ptr = head;
                            while(ptr->next != NULL ){
                                ptr = ptr->next;
                            }
                            head = insert_node (head, ptr, factor);
                        }
                        head_first = insert_first(head_first, NULL, factor);
                    }
                    
                    factor.data= factor.data+1;
                }
                puts("\n");
                break;
            case '3':
                ptr = head;
                while(ptr!=NULL){
                    if(prime(ptr->data)==0){
                        if(ptr->data == 1){
                        printf("%d不是質數\n", ptr->data);
                        }
                        else{
                        printf("%d是質數\n", ptr->data);
                        }
                    }
                    else{
                        printf("%d不是質數\n", ptr->data);
                    }
                    ptr = ptr->next;	
                }
                break;
                
            case '4':				
                ptr = head;
                while(ptr!=NULL){
                    printf("%d ", ptr->data);
                    ptr = ptr->next;	
                }
                
                puts("");				
                break;
            case '5':
                pt = head_first;
                while(pt!=NULL){
                    printf("%d ", pt->data);
                    pt = pt->next;	
                }
                puts("");				
                break;
            case '6':
                return 0;
                break;												
                
        }

    }	
    
    
    
    return 0;
}





