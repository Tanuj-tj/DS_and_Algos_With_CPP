#include <iostream>
using namespace std;

// Node Class
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

// Queue Main class

class Queue{
    Node* front; Node* rear;

    public:

    Queue(){
      front = NULL; rear = NULL;
    }

    void push(int x){
        Node* n = new Node(x);
        if(front==NULL){
            rear=n;
            front=n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    void pop(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"No elements in queue!!!"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front==NULL)
            return true;
        return false;
    }



};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;  // 1
    q.pop();
    cout<<q.peek()<<endl;  // 2
    q.pop();
    cout<<q.peek()<<endl;  // 3
    q.pop();
    cout<<q.peek()<<endl;  // 4
    q.pop();

    string check = q.empty()?"Queue is empty":"Queue is not empty";
    cout<<check;
    return 0;
}
