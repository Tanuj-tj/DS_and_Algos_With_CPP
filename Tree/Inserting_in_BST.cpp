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

void insert_iter(Node* root,int key){

    // Code for searching an element in a BST
    Node* r = NULL, *p;   // Initially *r = NULL 
    
    Node* t = root;
    if(root==NULL){
        p = new Node(key);
        p->left = p->right = NULL;
        root = p;
        return;
    }
    
    while(t!=NULL){
        r = t;
        if(key<t->data)
            t = t->left;
        else if(key>t->data)   
            t = t->right;
        else    
            return;
    }

    p = new Node(key);
    p->left = p->right = NULL;

    if(key< r->data)
        r->left = p;
    else
        r->right = p;

}

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    cout<<"Recursive Insertion in a BST :"<<endl;
    Node* root_rec = NULL;
    root_rec = insert_Recursively(root_rec,30);
    insert_Recursively(root_rec,40);
    insert_Recursively(root_rec,50);
    inorder(root_rec);

    cout<<endl;

    cout<<"Iterative Insertion in a BST :"<<endl;
    Node* root_itr = NULL;
    insert_iter(root_itr,30);
    insert_iter(root_itr,40);
    insert_iter(root_itr,50);

    inorder(root_itr);
   
    return 0;
}