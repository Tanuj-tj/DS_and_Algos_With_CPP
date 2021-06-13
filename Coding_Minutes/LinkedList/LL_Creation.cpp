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

    // If the head is pointing to the NULL
    if(head==NULL){
        // Create a new node and point it to next of head 
        head = new Node(data);
        return;
    }

    // If head is not pointing to NULL

    // Create a new node and point it to head and head to new node

    Node* n = new Node(data);
    n->next = head;
    head = n;

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

    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,3);

    printLL(head);
}