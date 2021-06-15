/*
Merge 2 Sorted Linked Lists
===========================

Given two sorted linked lists, merge them into a new linked list.

Input :
1-> 5 -> 7 -> 10 -> NULL
2-> 3 - > 6-> NULL

Output :
1->2->3->5->6->7->10

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

// Complexity : TC => O(l1+l2) , SC => O(l1+l2)
Node* merge_1(Node* l1, Node* l2){
    
    // Base cases

    if(l1==NULL){
        return l2;
    }

    if(l2==NULL){
        return l1;
    } 

    // Recursive case

    Node* ans;

    if(l1->data < l2->data){
        ans = l1;
        ans->next = merge_1(l1->next, l2);
    }
    else{
        ans = l2;
        ans->next = merge_1(l1,l2->next);
    }

    return ans;
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

    Node* head1 = NULL;

    insertAtHead(head1,1);
    insertAtHead(head1,5);
    insertAtHead(head1,7);
    insertAtHead(head1,10);
    printLL(head1);

    Node* head2 = NULL;

    insertAtHead(head2,2);
    insertAtHead(head2,3);
    insertAtHead(head2,6);
    printLL(head2);

    Node* head = merge_1(head1,head2);
    printLL(head);

    
}