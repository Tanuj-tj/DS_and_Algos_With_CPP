#include<bits/stdc++.h>
using namespace std;

class Node{
    
    public:
	
	Node* left;        // 0
	int data;         // 10
	Node* right;       // 0
	
	Node(int val){
	    left = NULL;
	    data = val;
	    right = NULL;
	}
}; 

// No. of elements in a binary tree
int count(Node *root){
    int x,y;
    if(root){
        return count(root->left) + count(root->right) + 1;
    }
    return 0;
}

// Hight of a binary tree
int height(Node *root){
    int x,y;
    if(root==0)
        return 0;
    x = height(root->left);
    y = height(root->right);

    if(x>y)
        return x+1;
    else
        return y+1;
}

// Counting Leaf nodes (Leaf nodes are with degree zero)
int count_leaf_node(Node *root){
    int x,y;
    if(root!=NULL){
        x = count_leaf_node(root->left);
        y = count_leaf_node(root->right);
   
        if(root->left==NULL && root->right==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

// Counting Non Leaf nodes (Leaf nodes are with degree two)
int count_Nonleaf_node_2(Node *root){
    int x,y;
    if(root!=NULL){
        x = count_Nonleaf_node_2(root->left);
        y = count_Nonleaf_node_2(root->right);
   
        if(root->left!=NULL && root->right!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

// Counting Non Leaf nodes (Leaf nodes are with degree one and tow)
int count_Nonleaf_node_1_2(Node *root){
    int x,y;
    if(root!=NULL){
        x = count_Nonleaf_node_1_2(root->left);
        y = count_Nonleaf_node_1_2(root->right);
   
        if(root->left!=NULL || root->right!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int main(){
	Node *root = new Node(10);            // Obj created in heap
   //Node root                         // Obj Created in stack
    
    root->left = new Node(11);
    root->right = new Node(12);

    root->right->right = new Node(15);
    
    root->left->left = new Node(13);
    root->left->right = new Node(14);

    root->left->left->left = new Node(16);
    root->left->left->right = new Node(17);

    cout<<"Count : "<<count(root)<<endl;
    cout<<"Height : "<<height(root)<<endl;
    cout<<"Count the Leaf nodes : "<<count_leaf_node(root)<<endl;
    cout<<"Count the Non Leaf nodes with degree 2 : "<<count_Nonleaf_node_2(root)<<endl;
    cout<<"Count the Non Leaf nodes with degree 1&2 : "<<count_Nonleaf_node_1_2(root)<<endl;

    /* 
        10
       / \
      11  12
     /  \  \ 
    13  14  15
   /  \    
  16  17  
    */
    
  
	return 0;
}