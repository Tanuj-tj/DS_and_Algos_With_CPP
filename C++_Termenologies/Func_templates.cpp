#include<iostream>
using namespace std;

template <class z> 
z find_max(z num1 ,z num2){
    if(num1>num2){
        return num1;
    }
    else{
        return num2;
    }
}

int main(){

    cout<<find_max(22.33,10.0)<<endl;
    cout << find_max<double>(3.01, 7.01) << endl; 
    return 0;
}
