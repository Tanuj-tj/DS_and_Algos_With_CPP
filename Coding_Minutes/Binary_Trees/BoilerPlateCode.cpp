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

// I/P : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

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

int main(){

    node* root = buildTree();

}

/*
Tree :

        1 
       / \
      2   3
     / \   \ 
    4   5   6
       /
      7


*/