/*
K- Reverse
==========

Given a linked list, write a function to reverse every k
nodes (where k is an input to the function).

Input :
1->2->3->4->5->6->7->8->NULL
K = 3

Output :
3->2->1->6->5->4->8->7->NULL

*/



#include <bits/stdc++.h>
using namespace std;


// Node class

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }   
};

//-------------Linked List----------------//

void insertAtHead(Node* &head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }

    Node* n = new Node(data);
    n->next = head;
    head = n;

}

Node* kreverse(Node* head, int k){

    if(head==NULL) return head;

    // Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next; 
    int cnt = 1;

    while(curr!=NULL and cnt <= k){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next; 
        cnt++;
    }

    //Inorder to reverse remaing nodes
    if(prev!=NULL){
        head->next = kreverse(next,k);
    } 

    return prev;
}

// Print the linked list

void printLL(Node* head){
    cout<<"HEAD->";
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;

}

int main(){

    Node* head = NULL;

    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,7);
    insertAtHead(head,8);
    printLL(head);
    
    int k = 3;
    head = kreverse(head,k);
    
    printLL(head);

    
}

