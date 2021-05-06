#include<iostream>
using namespace std;

// Time : O(1) Space : O(1)
int Formula(int n){
    return n * (n + 1) / 2;
}
// Time : O(n) Space : O(1)
int Loop(int n){
    int i,s=0;
    for(int i=0;i<=n;i++){
        s=s+i;
    }
    return s;
}
// Time : O(n) Space : O(n)
int Recursion(int n){
    if(n==1)
        return 1;

    return n + Recursion(n-1);
}

int main(){

    int n = 5;
    cout<<"Using Direct Formula : "<<Formula(n)<<endl;
    cout<<"Using Loop : "<<Loop(n)<<endl;
    cout<<"Using Recursion : "<<Recursion(n)<<endl;
}
