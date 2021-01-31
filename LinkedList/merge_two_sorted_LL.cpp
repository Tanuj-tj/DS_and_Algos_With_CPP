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

Node* merge(Node* &head1,Node* &head2){
    Node* p1 = head1;
    Node* p2 = head2;
    Node* dummyNode = new Node(-1);
    Node* p3 = dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3 = p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
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
 
    Node* head1 = NULL;
    int arr1[]={1,4,5,7};
    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }
    cout<<"LinkList One: ";
    display(head1);
    Node* head2 = NULL;
    int arr2[]={2,3,6};
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }
    cout<<"LinkList Two: ";
    display(head2);

    Node* newhead = merge(head1,head2);
    cout<<"Merged LinkList: ";
    display(newhead);
    return 0;
}