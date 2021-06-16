/*
Merge Sort Linked List
======================

Given a linked list, write a function to sort the linked list using Merge Sort.

Input :
3->2->1->6->5->4->8->7->NULL

Output :
1—>2->3->4->5->6->7->8->NULL
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

// --------------------------------------//

Node* merge(Node* a, Node* b){
    
    // base case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }

    Node* c;

    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }

    return c;
}



Node* midPoint(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node* mergeSort(Node* head){

    if(head==NULL or head->next==NULL){
        return head;
    }

    // Mid value
    Node* mid = midPoint(head);

    Node* a = head;
    Node* b = mid->next;
    mid->next = NULL;

    //Revursive call
    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);

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
    
    insertAtHead(head,7);
    insertAtHead(head,8);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    printLL(head);

    head = mergeSort(head);
    printLL(head);

}