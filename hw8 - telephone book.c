#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Binary_Tree_Node{
    
    int data;
    char name[80];
    char phone[11];
    struct  Binary_Tree_Node * left;
    struct  Binary_Tree_Node * right;
    
};

typedef struct  Binary_Tree_Node node;

void print_inorder(node *ptr){
    if(ptr != NULL){
        print_inorder(ptr->left);
        //printf("%d ", ptr->data);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %s\n\n", ptr->phone);
        print_inorder(ptr->right);
    }
}

void print_preorder(node *ptr){
    if(ptr != NULL){
        //	printf("%d ", ptr->data);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %s\n\n", ptr->phone);
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

void print_postorder(node *ptr){
    if(ptr != NULL){
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        printf("Name: %s\n", ptr->name);
        printf("Phone: %s\n\n", ptr->phone);
        //printf("%d ", ptr->data);
    }
}


//node *insert_node(node *root, int value)
node *insert_node(node *root, node input)
{
    node *new_node;
    node *current;
    node *parent;
    
    new_node = (node *)malloc(sizeof(node));
    //new_node->data = value;
    *new_node = input; //整塊記憶體空間放進去
    new_node->left = NULL;
    new_node->right = NULL;
    
    if(root == NULL){
        return new_node;
    }
    else{
        current = root;
        while(current != NULL){
            parent = current;
            if(strcmp(current->name,input.name) > 0 )
                current = current->left;
            else
                current = current->right;
        }
        //	if(parent->data > value)
        if(strcmp(parent->name,input.name) > 0 )
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}

node *find_node(node *ptr, char value[80]){
    while(ptr != NULL){
        if(strcmp(ptr->name, value) == 0){
            return ptr;
        }
        else{
            if(strcmp(ptr->name, value) > 0)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return NULL;
}


// 找某值之父節點
node *find_parent(node *ptr, char value[80], int *pos) //POS在這裡的反應都會影響到原本的pos
{
    node *parent;
    parent = ptr;	// 從ptr開始找
    *pos = 0;
    while(ptr != NULL)
    {
        if(strcmp(ptr->name, value)==0)	// 找到目標 (此時目標= root節點)
            return parent;		// 回傳此節點之父節點
        else
        {
            parent = ptr;
            if(strcmp(ptr->name, value)>0)
            {
                *pos = -1;			// ptr在parent左子樹
                ptr = ptr->left;	// 往左找
            }
            else
            {
                *pos = 1;			// ptr在parent右子樹
                ptr = ptr->right;	// 往右找
            }
        }
    }
    return NULL;	// 找不到
}


// 刪除節點
node *delete_node(node *root, char value[80])
{
    node *parent;
    node *ptr;
    node *next;
    int pos; //儲存現在是父結點的左邊還是右邊
    
    parent = find_parent(root, value, &pos);	// 從root開始,找value之父節點
    if(parent != NULL)	// 有找到, 準備刪除
    {
        switch(pos)	// 判斷目前節點再父節點左邊或右邊 // 此處的目的是還原ptr (在跑完find_parent以後ptr就消失了, 而ptr指的是我們要刪的東西)
        {
            case -1:
                ptr = parent->left;
                break;
            case 1:
                ptr = parent->right;
                break;
            case 0:
                ptr = parent;
                break;
        }
        if(ptr->left == NULL)		// 情況1: 節點沒有左子樹 如果要刪的是根節點
        {
            if(parent == ptr)	// 如果要刪的是根節點
                root = root->right;
            else				// 其他
            {
                if( pos == 1 )
                {
                    //要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的右節點
                    parent->right = ptr->right;
                }
                else
                {
                    //要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的右節點
                    parent->left = ptr->right;
                }
            }
            free(ptr);
        }
        else if(ptr->right == NULL)	// 情況2: 節點沒有右子樹
        {
            if(parent != ptr)
            {
                if( pos == 1 )
                {
                    //要刪除的節點在父節點右方,所以將父節點的右節點指向刪除節點的左節點
                    parent->right = ptr->left;
                }
                else
                {
                    //要刪除的節點在父節點左方,所以將父節點的左節點指向刪除節點的左節點
                    parent->left = ptr->left;
                }
            }
            else
                root = root->left;
            free(ptr);
        }
        else						// 情況3: 節點有左右子樹
        {
            parent = ptr;
            next = ptr->left;	// 找取代點next, 從ptr左邊開始找
            if(next->right != NULL){
                
                while(next->right != NULL)	// 往左子節點之右子樹找最大值當取代點
                {
                    parent = next;		// parent為next之父節點
                    next = next->right;
                }
                parent->right = next->left; // 繞過next節點
            }
            else{ //一開始就沒有右子樹的話
                ptr->left = next->left ;
            }
            
            ptr->data = next->data;		// 取代!!
            free(next);	// 刪除next (注意: 不是刪除ptr)
            
        }
    }
    return root;	// 回傳此樹
}





int main() {
    
    char op;
    //int value;
    char value[80];
    node input; //把資料整包放進去 
    
    node *root = NULL;
    node *ptr;
    
    
    while(1){
        
        /*puts("i insert");
        puts("f find");
        puts("d delete");
        puts("l list-inorder");
        puts("m list-preorder");
        puts("n list-postorder");
        puts("q quit");*/
        
        scanf(" %c", &op);
        
        switch(op){
            case 'i':
                //printf("name");
                scanf("%s", &input.name);
                //printf("phone");
                scanf("%s", &input.phone);
                root = insert_node(root, input);	
                break;
            case 'f':
                //	printf("要找的");
                scanf("%s" , &value);
                ptr = find_node(root, value);
                if(ptr != NULL){
                    puts("found:");
                    printf("Name: %s\n", ptr->name);
                    printf("Phone: %s\n", ptr->phone);
                }
                else{
                    puts("Not found");
                }
                puts("");
                break;
            case 'd':
                //	printf("要刪的");
                scanf("%s" , &value);
                ptr = find_node(root, value);
                if(ptr != NULL){
                    root = delete_node(root, value);
                    printf("delete %s ok\n", value);
                    
                }
                else{
                    puts("Cannot delete");
                }
                puts("");
                break;
            case 'l':
                print_inorder(root);
                break;
            case 'm':
                print_preorder(root);
                break;
            case 'n':
                print_postorder(root);
                break;
            case 'q':
                return 0;
                break;
        }
       system("pause");
       system("cls");
        
        
    }
    return 0;
}


