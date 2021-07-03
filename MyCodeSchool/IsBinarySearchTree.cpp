#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problem : Is the given binary tree a binary search tree


Approach 1: O(N^2)

Check for the root node as it follows the properties of BST 
(i.e. left subtree smaller and right subtree larger ) or not
Then Recursively check all the remaining nodes 

bool IsSubTreeLesser()

bool IsSubTreeGreater()

bool IsBinarySearchTree()


bool IsSubTreeLesser(BstNode* &root,int val){
    
    if(root == NULL) return true;
    
    if(root->data <= val
      && IsSubTreeLesser(root->left, val) 
      && IsSubTreeLesser(root->right,val)){
          
          return true;
      }
      
      else{
          return false;
      }
    
}
bool IsSubTreeGreater(BstNode* &root,int val){
    
    if(root == NULL) return true;
    
    if(root->data <= val
      && IsSubTreeGreater(root->left, val) 
      && IsSubTreeGreater(root->right,val)){
          
          return true;
      }
      
      else{
          return false;
      }
    
    
}

bool IsBinarySearchTree(BstNode* &root){
    
    if(root == NULL) return true;
    
    if( IsSubTreeLesser(root->left,root->data) 
        && IsSubTreeGreater(root->right,root->data) 
        && IsBinarySearchTree(root->left)  
        && IsBinarySearchTree(root->right)) {
        
        return true;
    }
    else{
        return false;
    }
}


*/


/*
Approach 2: O(N)

Find the max of left subtree and check if it is lesser then the root and 
Find the min of right subtree and check if it is greater then the root 


*/



// Node

class BstNode{
    
    public:
    BstNode* left;
    int data;
    BstNode* right;
    
    BstNode(int val){
        left = NULL;
        data = val;
        right = NULL;
    }
};

// Func -> IsBinarySearchTree

// Approach 2:

bool IsBSTUtil(BstNode* &root,int minVal,int maxVal){
    
    if(root == NULL) return true;
    
    if( root->data > minVal 
      && root->data < maxVal
      && IsBSTUtil(root->left, minVal, root->data)
      && IsBSTUtil(root->right, root->data, maxVal)) {
        
        return true;
    }
    else{
        return false;
    }
}

bool IsBinarySearchTree(BstNode* &root){
    return IsBSTUtil(root,INT_MIN,INT_MAX);
}

void PreOrder(BstNode* &root){
    if(root==NULL){
      return;  
    } 
    
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}


int main()
{
    BstNode* root = new BstNode(10);
    root->left = new BstNode(8);
    root->right =  new BstNode(12);
    
    root->left->left = new BstNode(7);
    root->left->right =  new BstNode(9);
    
     PreOrder(root);
    
    cout<<IsBinarySearchTree(root);
    

    return 0;
}
