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

bool Search(BstNode* &root,int data){
    
    if(root==NULL) return false;
    
    if(root->data == data) return true;
    
    else if(data <= root->data){
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);   
    }
}

int main()
{
    BstNode* root = NULL;
    
    Insert(root,15);
    Insert(root,10);
    Insert(root,20);
    Insert(root,25);
    
    
    int num = 100;
    
    if(Search(root,num)) cout<<"Found";
    else cout<<"Not Found";
    

    return 0;
}
