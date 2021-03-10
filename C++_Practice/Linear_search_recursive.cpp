#include<iostream>
using namespace std;

bool Linear_Search(int arr[],int n,int k){
    

    if(arr[n]==k){
        return true;
    }
    if(n==0){
        Linear_Search(arr,n-1,k);
    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    int n=5;
    int k=10;
    cout<<Linear_Search(arr,n,k)<<endl;
    return 0;
}