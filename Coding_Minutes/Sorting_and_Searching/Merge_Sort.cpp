#include <bits/stdc++.h>
using namespace std;

/* Steps :
   1. Divide
   2. MergeSort(Left) and MergeSort(Right)
   3. Merge(left+Right)
*/ 

// Merge
// Helper Function
void merge(vector<int> &arr,int s,int e,int mid){  // s = 0, e = 1
    int i=s;  // 0
   // int mid = (s+e)/2;  // 0
    int j=mid+1;  // 1

    vector<int> temp;  //[5,10]

    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);   // 5
            j++;
        }
    }  

    // If elements still remains in any part of array
    while(i<=mid){
        temp.push_back(arr[i++]);  // 10
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    int k=0;
    for(int idx=s;idx<=e;idx++){
        arr[idx] = temp[k++];
    }
    // 0  1
    // 5 10
    return;

}

// Merge Sort
void mergesort(vector<int> &arr,int s,int e){
    // Base case
    if(s>=e){
        return;
    } 
    // Divide 
    int mid = ( s + e ) / 2;
    mergesort(arr,s,mid);    // 2
    mergesort(arr,mid+1,e);   // 0
    return merge(arr,s,e,mid);  // (arr, 0, 1) [5,10] (arr, 2,3) [0,2]

}

int main(){

    vector<int> arr{10,5,2,0,7,6,4};
    
    int s = 0;
    int e = arr.size()-1;

    mergesort(arr,s,e);

    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
