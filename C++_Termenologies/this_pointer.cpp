#include<iostream>
using namespace std;

/*OBJECT POINTER */

class Box{
    
    private:
    int l,b,h;
    
    public:
    void set_Dim(int l,int b,int h){
        /* Here name conflict occurs so,
           both of the l ,b and h are considered as a local variable
           l=l;
           b=b;
           h=h; */

        // Here this pointer will represet the caller object pointer
        this->l = l;
        this->b = b;
        this->h = h;
    }
    void show_Dim(){
        cout<<l<<" "<<b<<" "<<h<<" "<<endl;
    }
    

};

int main(){
    
    Box smallBox;

    smallBox.set_Dim(12,10,5);
    smallBox.show_Dim();

    return 0;
}