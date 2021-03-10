#include<iostream>
using namespace std;

class Shape{
    public:
    virtual float area()=0;
    virtual float parimeter()=0;
};

class Rectangle:public Shape{
    private:
    float length,bredth;
    public:
    Rectangle(float length=1,float bredth=1){
        this->length=length;
        this->bredth=length;
    }
    float area(){
        return length*bredth;
    }
    float parimeter(){
        return 2*(length+bredth);
    }
};
class Circle:public Shape{
    private:
    float radius;
    public:
    Circle(float radius){
        this->radius=radius;
    }
    float area(){
        return 3.1425*radius*radius;
    }
    float parimeter(){
        return 2*3.1425*radius;
    }
};


int main(){
    Shape *p = new Rectangle(5,2);
    cout<<"Area of Rectangle is: "<<p->area()<<endl;
    cout<<"Paremeter of Rectangle is: "<<p->parimeter()<<endl;

    p = new Circle(5);
    cout<<"Area of Circle is: "<<p->area()<<endl;
    cout<<"Paremeter of Circle is: "<<p->parimeter()<<endl;
    
}