/* 

Delete a node from a Binary Search Tree :

Case 1 : Node is a Leaf Node
          -> Just delete the node
          
Case 2 : Node consist of Single Child
          -> Replace the node with the child node
          
Case 3 : Node consist of 2 childs
          -> Replace the current node with the min of its left subtree or max of its right subtree
*/
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

// Find min

int FindMin(BstNode* &root){
    
     BstNode* curr = root;

    if(curr->left==NULL){
        return curr->data;
    }
    
    return FindMin(curr->left);
}


// Delete

void Delete(BstNode* &root, int data){

    // If the tree is empty
    if(root==NULL) return;
    
    // Find the Node which we want to delete
    else if(root->data < data){
        Delete(root->right,data);
    }
    else if(root->data > data){
        Delete(root->left,data);
    }
    else{
       
       // Case 1 :
       if(root->left == NULL and root->right == NULL){
          delete root;
          root = NULL;
       }
       
       // Case 2 :
       else if(root->left == NULL){
           BstNode* temp = root;
           root = root->right;
           delete temp;
       }
       
       else if(root->right == NULL){
           BstNode* temp = root;
           root = root->left;
           delete temp;
       }
       
       // Case 3 :
      else{
          int temp = FindMin(root->right); // or Node* temp = FindMax(root->left);
          root->data = temp;
          Delete(root->right,temp);
      }

    }

}

// Traverse

void PreOrderTraverse(BstNode* &root){
    
    if(root==NULL){
        return; 
    }
    
    cout<<root->data<<" ";
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}

int main()
{
    BstNode* root = NULL;
    
    Insert(root,12);
    Insert(root,5);
    Insert(root,15);
    Insert(root,3);
    Insert(root,7);
    Insert(root,13);
    Insert(root,17);
    Insert(root,1);
    Insert(root,9);
    
    cout<<"Before Deletion"<<endl;
    PreOrderTraverse(root);
    
    Delete(root,9);
    
    cout<<endl;
    
    cout<<"After Deleting Leaf node"<<endl;
    PreOrderTraverse(root);
    
    Delete(root,7);
    
    cout<<endl;
    
    cout<<"After Deleting node with 1 child"<<endl;
    PreOrderTraverse(root);
    
    
    Delete(root,15);
    
    cout<<endl;
    
    cout<<"After Deleting node with 2 child"<<endl;
    PreOrderTraverse(root);


    return 0;
}

/*

Output :

Before Deletion
12 5 3 1 7 9 15 13 17 
After Deleting Leaf node
12 5 3 1 7 15 13 17 
After Deleting node with 1 child
12 5 3 1 15 13 17 
After Deleting node with 2 child
12 5 3 1 17 13


*/

