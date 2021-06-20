/*
Implement Level order Treaversal

O/P :

1
2 3
4 5 6
7

Using a explicit queue

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

// Building a preorder tree

node* buildTree(){

    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;

}

void levelOrderPrint(node* root){

    // Create a queue and push the head node

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

    node* root = buildTree();

    levelOrderPrint(root);

}

// I/P : 1 2 3 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1