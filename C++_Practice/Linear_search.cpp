#include<iostream>
using namespace std;

bool Linear_Search(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k)
            return true;
    }
    return false;
}

int main(){

    int arr[] = {1,2,3,4,5};
    int n=5;
    int k=4;
    string ans = Linear_Search(arr,n,k) ? "True":"False";
    cout<<ans<<endl;
    return 0;
}