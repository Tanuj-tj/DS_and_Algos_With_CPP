/*
BUILD A TREE (Level Order)
==========================

Build a Binary Tree from Level Order Input -1 in input represents NULL

I/P : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1

O/P :   

          1
        /    \
       2      3
      / \    / \
     4   5 -1   6
    / \ / \    / \
  -1 -1 7 -1  -1  -1
        /\
      -1 -1

*/

#include <bits/stdc++.h>
using namespace std;

// Node Class

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Building a level order tree

node* LevelOrderBuild(){

    int d; cin>>d;

    node* root = new node(d);
    
    queue<node*> q;
      
    q.push(root);

    while(!q.empty()){

        node* current = q.front();
        q.pop();

        int c1, c2;
        cin>>c1>>c2;

        if(c1!=-1){
            current->left = new node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right = new node(c2);
            q.push(current->right);
        }
    }

    return root;
}

// Level order print

void LevelOrderPrint(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();

        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    return;
}

int main(){

    node* root = LevelOrderBuild();
    LevelOrderPrint(root);

    return 0;
}