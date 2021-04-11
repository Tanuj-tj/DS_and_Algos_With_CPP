#include<iostream>
using namespace std;

int y = 0; // Global Variable

int fun(int n){
    
    static int x =0; // Static Variable
    if(n>0){
        x++;  
        y++;
        return fun(n-1)+x+y;
    }
    return 0;
}

int main(){

    int n = 5;
    cout<<fun(n)<<endl;
    cout<<fun(n)<<endl;
    cout<<fun(n)<<endl;
}