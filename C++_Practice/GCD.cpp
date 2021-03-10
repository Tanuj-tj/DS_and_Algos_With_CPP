#include<iostream>
using namespace std;
int main(){

    cout<<"Enter 2 nos.:"<<endl;
    int m,n; cin>>m>>n;

    while(m!=n){

        if(m>n){
            m = m-n;
            cout<<m<<" "<<n<<endl;
        }
        else{
            n = n-m;
            cout<<m<<" "<<n<<endl;
        }
    }
    return 0;
}