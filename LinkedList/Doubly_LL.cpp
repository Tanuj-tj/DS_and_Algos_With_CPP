// Doubly Linked List

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Insert At Head

void insAtHead(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

// Insert At tail

void insAtTail(node* &head,int val){

    if(head==NULL){
        insAtHead(head,val);
        return;
    }
 
    node* n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

// Deletion on Doubly LL

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deletion(node* head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count = 1;

    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

// Display Doubly Lined List

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){

    node* head=NULL;
    
    insAtHead(head,1);
    insAtHead(head,2);
    insAtTail(head,3);
    insAtTail(head,4);
    display(head);
    deletion(head,4);
    cout<<"After Deletion"<<endl;
    display(head);

    return 0;
}