/*

2 Approachs :

Approach 1: Bruit Force => O(N^2)
Approach 2: Soring and Two Pointer Technique => O(N)

*/


#include<bits/stdc++.h>
using namespace std;

bool Approach_1(int arr[],int n,int k){

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
    
}

bool Approach_2(int arr[],int n,int k){
    int low = 0;
    int high = n-1;

    // If in case the elements are not sorted
    sort(arr, arr + n);

    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high]>k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}

int main(){
 
    int n=8;
    int arr[] = {2,4,7,11,14,16,20,21};
    int k=37;
  
    cout<<"Bruit Force => O(N^2) : "<<endl;
    cout<<Approach_1(arr,n,k)<<endl;
    cout<<"Soring and Two Pointer Technique => O(N) : "<<endl;
    cout<<Approach_2(arr,n,k)<<endl;
}