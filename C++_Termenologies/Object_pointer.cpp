#include<iostream>
using namespace std;

/*OBJECT POINTER */

class Box{
    
    private:
    int l,b,h;
    
    public:
    void set_Dim(int x,int y,int z){
        l=x;
        b=y;
        h=z;
    }
    void show_Dim(){
        cout<<l<<" "<<b<<" "<<h<<" "<<endl;
    }
    

};

int main(){

    Box *p,smallBox;
    p=&smallBox; 

    smallBox.set_Dim(12,10,5);
    smallBox.show_Dim();

    p->set_Dim(12,10,5);
    p->show_Dim();

    return 0;
}