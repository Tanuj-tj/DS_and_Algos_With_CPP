#include<iostream>
using namespace std;

class Rectangle{

    public:
    int length,bredth;
    int area(){
        return length*bredth;
    }
};


int main(){


    cout<<"Creating a normal object"<<endl;
    Rectangle n1;
    n1.length = 10;
    n1.bredth = 10;
    cout<<n1.area()<<endl;

    cout<<"Creating a pointer object"<<endl;
    Rectangle n;
    Rectangle *q;
    q = &n;
    q->length = 20;
    q->bredth = 20;
    cout<<q->area()<<endl;

    cout<<"Creating a object inside heap"<<endl;
    Rectangle *p = new Rectangle();
    p->length = 30;
    p->bredth = 30;
    cout<<p->area()<<endl;
    return 0;
}