/*
Middle Element
==============

This is an easy problem! Apply runner technique to find mid-point of a given linked list in a single pass.

Input :
Head of the Linked List is given as input.
1->2->3->4->5->6->7->8

Output :
4
*/



#include<bits/stdc++.h>
using namespace std;


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

int getMid(Node *head){
    //Complete this function to return data middle node
    
    // Runner Technique - slow and fast pointers

    Node* slow = head;
    Node* fast = head;
    
    while(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow->data;
    
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

    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);

    cout<<getMid(head)<<endl;

}