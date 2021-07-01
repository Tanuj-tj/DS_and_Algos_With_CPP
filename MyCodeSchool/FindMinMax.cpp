#include <iostream>

using namespace std;

class BstNode{
  public:
   BstNode* left;  // Left Child Reference
   int data;     // Data
   BstNode* right;  // // Right Child Reference
   
   BstNode(int val){
       left = NULL;
       data = val;
       right = NULL;
   }
};

BstNode* Insert(BstNode* &root, int data){
    
    if(root == NULL){
        BstNode* newNode = new BstNode(data);
        root = newNode;
    }
    
    // 2 more cases
    
    else if(data <= root->data){
        root->left = Insert(root->left,data);
    }
    else{
        root->right = Insert(root->right,data);
    }
    
    return root;
}

// Find min and max Node

// Using Itteration
int FindMinIter(BstNode* &root){
    
    if(root==NULL){
        cout<<"Tree is empty";
        return -1;
    }
    
    BstNode* curr = root;
    
    while(curr->left){
        curr = curr->left;
    }
    
    return curr->data;
}

int FindMaxIter(BstNode* &root){
    
    if(root==NULL){
        cout<<"Tree is empty";
        return -1;
    }
    
    BstNode* curr = root;
    
    while(curr->right){
        curr = curr->right;
    }
    
    return curr->data;
}

// Using Recursion
int FindMinRec(BstNode* &root){
    
     BstNode* curr = root;
    
    if(root==NULL){
        cout<<"Tree is empty";
        return -1;
    }

    else if(curr->left==NULL){
        return curr->data;
    }
    
    return FindMinRec(curr->left);
}

int FindMaxRec(BstNode* &root){
    
    
    BstNode* curr = root;
    if(root==NULL){
        cout<<"Tree is empty";
        return -1;
    }
    else if(curr->right==NULL){
        return curr->data;
    }
    
    return FindMaxRec(curr->right);
}




int main()
{
    BstNode* root = NULL;
    
    Insert(root,15);
    Insert(root,10);
    Insert(root,20);
    Insert(root,25);
    Insert(root,17);
    Insert(root,12);
    
    
    cout<<FindMinIter(root)<<endl;
    cout<<FindMaxIter(root)<<endl;
    
    cout<<FindMinRec(root)<<endl;
    cout<<FindMaxRec(root)<<endl;
    
    
    

    return 0;
}
