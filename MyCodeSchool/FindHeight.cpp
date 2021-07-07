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

// Height of tree , TC : O(N)

int FindHeight(BstNode* root){
    
    // Recursice call to find the height of left and right sub tree
    
    BstNode* curr = root;
    
    // Base cases
    // If we are counting the no. of edges return -1
    // If we are counting the no. of nodes return 0
    if(curr==NULL){
        return -1;  
    }
    
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    
    return max(leftHeight, rightHeight) + 1;
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
    Insert(root,30);
    
    
    
    cout<<FindHeight(root);
    
    return 0;
}

// OP : 3
