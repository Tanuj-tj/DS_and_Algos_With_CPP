#include<iostream>
using namespace std;

int main(){

    int n,i;
    float arr[100];
    float sum = 0.0;

    cout<<"Enter the no. of elements: "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){

        cout<< i+1<<"Enter No. :";
        cin>>arr[i];
        sum += arr[i];
    }
    
    float avg = sum/n;
    cout<<avg<<endl;

    return 0;
}