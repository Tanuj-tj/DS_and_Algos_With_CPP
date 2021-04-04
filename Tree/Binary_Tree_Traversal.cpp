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

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
	
}
void levelorder(Node* root){

    // Base Condition
    if(root == NULL)
        return ;

    queue<Node*> q; // Empty Queue

    q.push(root);

    while(!q.empty()){
        

        // Print front of queue and remove it from queue
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();
  
        // Enqueue Left Child
        if(node->left != NULL){
            q.push(node->left);
        }
        // Enqueue right Child
        if(node->right != NULL){
            q.push(node->right);
        }
    }

}

int main(){
	Node *root = new Node(10);            // Obj created in heap
   //Node root                         // Obj Created in stack
    
    root->left = new Node(11);
    root->right = new Node(12);
    
    root->left->left = new Node(13);
    root->left->right = new Node(14);
    
    cout<<"Preorder : ";
    preorder(root);
    cout<<endl;
    
    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;
    
    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;

    cout<<"Levelorder : ";
    levelorder(root);
    cout<<endl;
    
    /* 
        10
       / \
      11  12
     /  \
    13  14
    
    */
    
  
	return 0;
}
