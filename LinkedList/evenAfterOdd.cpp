//// Put even Elements after Odd elements in a LL

#include <iostream>
using namespace std;

// Creating a node 
class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

// Insert a new node at the end of a LL
void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
    
}
// Traversing a circular LL
void display(node* head){
   node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// Put even Elements after Odd elements in a LL
void evenAfterOdd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;
    
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next!=NULL){
        even->next=NULL;
    }
}

int main()
{
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    cout<<"LL: "<<endl;
    display(head);
    cout<<"Even Elements after Odd elements"<<endl;
    evenAfterOdd(head);
    display(head);
    
    return 0;
}
