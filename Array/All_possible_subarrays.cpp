#include<iostream>
using namespace std;

void subarrays(int arr[],int n){

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }cout<<endl;
        }
    }
}

int main(){
    int arr[] = {-1,4,7,2};
    subarrays(arr,4);

    return 0;
}