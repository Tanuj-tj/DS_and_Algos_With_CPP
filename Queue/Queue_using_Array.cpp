#include <iostream>
using namespace std;

#define n 20

class Queue{

    int *arr;
    int front;
    int rear;

    public:
    Queue(){
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Enqueue/Push Operation 
    void push(int x){

        // If our rear is pointing to the last element of the queue
        if(rear == n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear++;

        arr[rear] = x;

        if(front == -1){
            front++;
        }
    }

    // Dequeue/Pop Operation
    void pop(){
        if(front==-1 || front>rear){
            cout<<"No elements in queue"<<endl;
            return;
        }
        front++;
    }

    // Peek Operation => return the 1st value in a queue
    int peek(){
        if(front==-1 || front>rear){
            cout<<"No elements in queue"<<endl;
            return -1;
        }

        return arr[front];
    }

    // Empty Operation => Will return if the queue is empty or not
    bool empty(){
        if(front==-1 || front>rear){
            return true;
        }
        return false;
    }

};

int main(){

    Queue q;
    q.push(1);
    cout<<q.peek()<<endl;
    string x = q.empty() ? "Queue is Empty" : "Queue is Not Empty";
    cout<<x<<endl;
    q.pop();
    q.push(2);
    cout<<q.peek()<<endl;
    q.pop();
    q.push(3);
    cout<<q.peek()<<endl;
    q.pop();
    x = q.empty() ? "Queue is Empty" : "Queue is Not Empty";
    cout<<x<<endl;


    return 0;
}
