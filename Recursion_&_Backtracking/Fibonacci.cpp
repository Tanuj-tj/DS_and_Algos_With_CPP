#include<iostream>
using namespace std;

// O(2^N)
int fib1(int n){
    if(n<=1){
        return n;
    }
    return fib1(n-2) + fib1(n-1);
}

// O(N)
int F[10];
int fib2(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2] = fib2(n-2);
        if(F[n-1]==-1)
            F[n-1] = fib2(n-1);
        
        return F[n-2]+F[n-1];
    }
}
int main(){
   
    int n = 5;
    cout<<fib1(n)<<endl;

    int i;
    for(i=0;i<10;i++){
        F[i]=-1;
    }

    cout<<fib2(n)<<endl;
    for(i=0;i<n;i++){
        cout<<F[i]<<" ";
    }

    return 0;
}