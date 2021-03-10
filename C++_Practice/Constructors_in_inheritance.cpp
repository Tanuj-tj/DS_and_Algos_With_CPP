#include<iostream>
using namespace std;

class Base{

    public:
    Base(){
        cout<<"Base Class Default Const."<<endl;
    }
    Base(int x){
        cout<<"Base Class Param. Const."<<x<<endl;
    }
};

class Derived:public Base{

    public:
    Derived(){
        cout<<"Derived Class Default Const."<<endl;
    }
    Derived(int a){
        cout<<"Derived Class Param. Const."<<a<<endl;
    }

    Derived(int x,int a):Base(x){
        cout<<"Param const. of Derived class "<<x<<" "<<a<<endl;
    }
};

int main(){

    Derived d;
    Derived d1(10);
    Derived d2(10,11);


    return 0;
}