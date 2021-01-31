#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

// Calculate the length of LL

int length(Node* head){
    int len = 0;
    Node* temp = head;
    
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

// Append Function 

Node* kappend(Node* &head,int k){
    Node* newhead;
    Node* newtail;
    Node* tail=head;

    int l = length(head);
    k = k % l;
    int count = 1;

    while(tail->next!=NULL){
        if(count==l-k){
            newtail=tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        tail = tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
} 

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"=>";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;

}
int main(){
    Node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);

    Node* newhead = kappend(head,4);
    display(newhead);

    return 0;
}