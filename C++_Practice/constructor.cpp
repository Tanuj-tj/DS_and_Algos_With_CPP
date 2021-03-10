#include<iostream>
using namespace std;

class Rectangle{

    private:
    int length,bredth;

    public:

     // Non Parametrized 
    Rectangle(){
        length = 0;
        bredth = 0;
    }
    // Parameterized
    Rectangle(int l,int b){
        setLength(l);
        setBredth(b);
    }
    // Copy
    Rectangle(Rectangle &rect){
        length = rect.length;
        bredth = rect.bredth;
    }

    void setLength(int l){
        if(l>0)
            length = l;
        else
            length = 1;
    }
    void setBredth(int b){
        if(b>0)
            bredth = b;
        else
            bredth = 1;
    }
    int getLength(){return length;}
    int getBredth(){return bredth;}

    int area(){return length * bredth;}

};

int main(){

    Rectangle R;
    cout<<R.area()<<endl;    
    Rectangle R1(10,15);
    cout<<R1.area()<<endl;
    Rectangle R2(R1);
    cout<<R2.area()<<endl;

    return 0;
}