/*
K-th Last
========

Implement a function that returns the Kth last of element from the linked list, in a single pass.
You can assume K will be less than / equal to length of linked list.

(Hint: Use two pointers similar to Runner Technique)


Input

You will get head of the linked list.
1 -> 2 —> 3 -> 4 -> 5 ->6 ->7
K = 3

Output
5


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

int kthLastElement(Node *head, int k){

    // 2 pointers

    Node* slow = head;
    Node* fast = head;

    int cnt = 1;
    while(cnt<=k){
        fast = fast->next;
        cnt++;
    }

    while(fast){
        fast = fast->next;
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

    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printLL(head);
    
    int k = 3;
    cout<<kthLastElement(head,k)<<endl;

}