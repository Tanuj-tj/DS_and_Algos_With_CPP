/*
Reverse a Linked List 
=====================

Given a Linked List, write a function to reverse the linked list.

Input :
1=>2=>3=>4=>5

Output :
5=>4=>3=>2=>1


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

// Revese Recursively  : TC => O(N) , SC => O(N)

Node* reverseRec(Node* head){
    
    // Base case
    if(head == NULL or head->next == NULL){
        return head;
    }

    Node* sHead = reverseRec(head->next);

    head->next->next = head;
    head->next = NULL;

    return sHead;
}

// Iterative Reverse : TC => O(N) , SC => O(1)

void reverseIter(Node* &head){

    // prev , curr, temp
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    
    while(curr){   // curr!=NULL
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head =  prev;
    return;
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
    
    int choice;cin>>choice;

    if(choice==1){
        // Recursive
        head = reverseRec(head);
        printLL(head);
    }
    else{
        // Iterative
       reverseIter(head);
       printLL(head);   
    }
}
