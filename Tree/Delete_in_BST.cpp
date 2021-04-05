#include<bits/stdc++.h>
using namespace std;

// A NODE
class Node{
    public:
    Node* left;
    int data;
    Node* right;

    Node(int val){
        left = NULL;
        data = val;
        right = NULL;
    }
};

Node* insert_Recursively(Node* p, int key){
    Node* t;
    if(p==NULL){
        t = new Node(key);
        t->left = t->right = NULL;
        return t;
    } 

    if(key<p->data){
        p->left=insert_Recursively(p->left,key);
    }
    else if(key>p->data){
        p->right=insert_Recursively(p->right,key);
    }
    return t;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

/* Deletion in a BST
 1. Key has no child
 2. Key has 1 child
 3. Key has more then 1 child
*/

int Height(Node* p){

    int x , y;
    if(p==NULL) return 0;
    x = Height(p->left);
    y = Height(p->right);
    return x>y ? x+1:y+1;
}


//Will Return Inorder Predecessor
Node* InPre(Node* p){
    while(p && p->right!=NULL)
        p = p->right;
    return p;
}

//Will return Inorder Successor 
Node* InSucc(Node* p){
    while(p && p->left!=NULL)
        p = p->left;
    return p;
}

Node* Delete(Node *p,int key){

    Node *q;
    if(p==NULL)
        return NULL;
    if(p->left==NULL && p->right==NULL){
        delete(p);
        return NULL;
    }
    // Searching the key, if found then perform deletion
    if(key < p->data)
        p->left = Delete(p->left,key);
    else if(key > p->data)
        p->right = Delete(p->right,key);

    else{
        if(Height(p->left) > Height(p->right)){

            // Inorder Predecessor
            q = InPre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,q->data);
        }
        else{
            // Inorder Successor
            q = InSucc(p->right);
            p->data=q->data;
            p->right=Delete(p->right,q->data);
        }
    }
    return p;
}

// Searching a element in BST
Node* Search(Node* root,int key){
    
    // If tree is empty
    if(root==NULL)
        return NULL;
    
    // If key is at the root node
    if(key==root->data)
        return root;

    // If Key is greater then root node data 
    else if(key > root->data )
        return Search(root->right,key);

    // If Key is less then root node data 
    else    
        return Search(root->left,key);

}

int main(){

    cout<<"Elements Before Deletion :"<<endl;
    Node* root_rec = NULL;
    root_rec = insert_Recursively(root_rec,30);
    insert_Recursively(root_rec,40);
    insert_Recursively(root_rec,50);
    insert_Recursively(root_rec,60);
    insert_Recursively(root_rec,90);
    inorder(root_rec);

    cout<<endl;
  
    int key = 30;
    cout<<"Search :",key;
    Node* temp = Search(root_rec,key);
    if(temp!=NULL)
        printf("element %d is found\n",temp->data);
    else
        printf("element is not found\n");

    cout<<"Elements after Deletion :"<<endl;
    Delete(root_rec,key);
    inorder(root_rec);
    
    cout<<endl;
    cout<<"Search :",key;
    Node* temp1 = Search(root_rec,key);
    if(temp1!=NULL)
        printf("element %d is found\n",temp1->data);
    else
        printf("element is not found\n");
   
    return 0;
}