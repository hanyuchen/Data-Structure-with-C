#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};


void print_inorder(node *ptr)
{
    
    if(ptr != NULL)
    {
        print_inorder(ptr->left);
        cout << ptr->data << " ";
        print_inorder(ptr->right);
    }
    
}

void print_preorder(node *ptr)
{
    
    if(ptr != NULL)
    {
        cout << ptr->data << " ";
        print_preorder(ptr->left);
        print_preorder(ptr->right);
    }
}

void print_postorder(node *ptr)
{
    
    if(ptr != NULL)
    {
        print_postorder(ptr->left);
        print_postorder(ptr->right);
        cout << ptr->data << " ";
        
    }
}
node *insert_node(node *root, int value)
{
    node *new_node;
    node *current;
    node *parent;
    
    new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    //*new_node = input;
    new_node->left = NULL;
    new_node->right = NULL;
    
    if(root == NULL)
    {
        return new_node;
    }
    else
    {
        current = root;
        while(current != NULL)
        {
            parent = current;
            if(current->data > value)
                current = current->left;
            else
                current = current->right;
        }
        if(parent->data > value)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    return root;
}

node *find_node(node *ptr, int value)
{
    while(ptr != NULL)
    {
        if(ptr->data == value)
            return ptr;
        else
        {
            if(ptr->data > value)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }
    return NULL;
}

node *find_parent(node *ptr, int value, int *pos)
{
    node *parent;
    
    parent = ptr;
    *pos = 0;
    while(ptr != NULL)
    {
        
        if(ptr->data == value)
            return parent;
        else
        {
            parent = ptr;
            if(ptr->data > value)
            {
                *pos = -1;
                ptr = ptr->left;
            }
            else
            {
                *pos = 1;
                ptr = ptr->right;
            }
        }
    }
    return NULL;
}
node *delete_node(node *root, int value)
{
    node *parent;
    node *ptr;
    node *next;
    int pos;
    
    parent = find_parent(root, value, &pos);
    if(parent != NULL)
    {
        switch(pos)
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
        if(ptr->left == NULL)		        {
            if(parent == ptr)
                root = root->right;
            else
            {
                if( pos == 1 )
                {
                    parent->right = ptr->right;
                }
                else
                {
                    parent->left = ptr->right;
                }
            }
            free(ptr);
        }
        else if(ptr->right == NULL)
        {
            if(parent != ptr)
            {
                if( pos == 1 )
                {
                    parent->right = ptr->left;
                }
                else
                {
                    parent->left = ptr->left;
                }
            }
            else
                root = root->left;
            free(ptr);
        }
        else
        {
            parent = ptr;
            next = ptr->left;
            if(next->right != NULL){
                while(next->right != NULL)
                {
                    parent = next;
                    next = next->right;
                }
                parent->right = next->left;
            }
            else{
                ptr->left = next->left;
            }
            ptr->data= next->data;
            free(next);
        }
    }
    return root;
}
int main()
{
    char op;
    int value;
    int d_num;
    
    
    node *root = NULL;
    node *ptr;
    int n=1;
    
    while(1)
    {
        
   /*     cout << "1 insert" << endl;
        cout << "2 list-inorder"<< endl;
        cout << "3 list-preorder"<< endl;
        cout << "4 list-postorder"<< endl;
        cout << "5 delete"<< endl;
        cout << "6 find"<< endl;
        cout << "8 quit"<< endl; */
        
        cin >> op;
        switch(op)
        {
            case '1':
                cin >> value;
                root = insert_node(root, value);
                break;
            case '2':
                print_inorder(root);
                cout << endl;
                break;
            case '3':
                print_preorder(root);
                cout << endl;
                break;
            case '4':
                print_postorder(root);
                cout << endl;
                break;
                
            case '5':
                cin >> d_num;
                ptr = find_node(root, d_num);
                if(ptr != NULL){
                    root = delete_node(root, d_num);
                    cout << "delete " << d_num << " ok" << endl;
                }
                else
                    cout << "cannot delete"<< endl;
                break;
                
            case '6':
                cin >> value;
                ptr = find_node(root, value);
                if(ptr != NULL)
                {
                    cout <<"found: " << ptr->data << endl;
                }
                else
                    cout <<"Not found" << endl;
                break;
                
            case '8':
                return 0;
                break;
                
        }
       /* system("pause");
        system("cls");*/
    }	
    return 0;
}
