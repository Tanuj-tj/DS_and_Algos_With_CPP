#include<bits/stdc++.h>
using namespace std;

// AVL Tree Node
// struct Node{
//     struct Node *left;
//     int data;
//     int height;
//     struct Node *right;
// }*root = NULL;

class Node{
    public:
    Node *left;
    int data;
    int height;
    Node *right;
    Node(int val){
        left = NULL;
        data = val;
        height = 1;
        right = NULL;
    }
};

int NodeHeight(Node* root){

    /*
    Check the height of the left subtree and the right subtree
    Return the greater height amoung them
    */

    int hl,hr; 
    /*
    If root and root->left are both exist(true)
          Get the height
    else
          Zero
    */
    hl = root && root->left ? root->left->height:0;
    hr = root && root->right ? root->right->height:0;

    return hl > hr ? hl+1 : hr+1;

}

int BalanceFactor(Node* root){
    /*
    Balance Factor = height of left subtree - height of right subtree
    BF = hl - hr
    */

    int hl,hr; 
    hl = root && root->left ? root->left->height:0;
    hr = root && root->right ? root->right->height:0;
    
    return hl-hr;
}

Node* LLRotation(Node* p){

    Node* pl = p->left;
    Node* plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    
    return pl;
}

Node* LRRotation(Node* p){
    Node* pl = p->left;
    Node* plr = pl->right;
  
    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    return plr;

}

Node* RRRotation(Node* root){
    return NULL;
}

Node* RLRotation(Node* root){
    return NULL;
}

Node* insert_Recursively(Node* root, int key){

    Node* t=NULL;

    if(root==NULL){
        t = new Node(key);
        t->left = t->right = NULL;
        return t;
    } 

    if(key < root->data){
        root->left=insert_Recursively(root->left,key);
    }
    else if(key > root->data){
        root->right=insert_Recursively(root->right,key);
    }

    root->height = NodeHeight(root);
    
    // Pereform Rotation LL , LR , RR, RL
    
    if(BalanceFactor(root)==2 && BalanceFactor(root->left)==1)
        return LLRotation(root);

    else if(BalanceFactor(root)==2 && BalanceFactor(root->left)==-1)
        return LRRotation(root);
    
    else if(BalanceFactor(root)==-2 && BalanceFactor(root->left)==-1)
        return RRRotation(root);
    
    else if(BalanceFactor(root)==-2 && BalanceFactor(root->left)==1)
        return RLRotation(root);

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

int main(){

    Node* root = NULL;
    root = insert_Recursively(root,10);
    insert_Recursively(root,5);
    insert_Recursively(root,2);
   
    inorder(root);


    return 0;
}