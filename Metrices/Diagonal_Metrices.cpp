#include<bits/stdc++.h>
using namespace std;

class Diagonal{

    private:
        int n; // nxn
        int *A;  // A[n][n]

    public:
        Diagonal(){
            n=2;
            A=new int[2];
        }
        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }
        ~Diagonal(){
            delete[]A;
        }
        void set(int i,int j,int x);
        int get(int i,int j);
        void Display();
        
};

void Diagonal::set(int i,int j,int x){
    if(i==j)
        A[i-1] = x;
}

int Diagonal::get(int i,int j){
    if(i==j)
        return A[i-1];
    else
        return 0;
}

void Diagonal::Display(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0"<<" ";
        }
        cout<<endl;
    }   
}

int main(){
    Diagonal m(4);

    m.set(1,1,5);
    m.set(2,2,8);
    m.set(3,3,9);
    m.set(4,4,12);
    
    m.Display();

    cout<<m.get(2,2)<<endl;
    return 0;
}