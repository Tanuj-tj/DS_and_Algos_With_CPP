#include<bits/stdc++.h>
using namespace std;

/*
Quick select
------------
Write a function that takes input an array of distinct
integers, and returns kth smallest in the array

Sample Input :
[10, 5, 2, 0, 7, 6, 4]
k =4

Sample Output :
5

*/

int partition(vector<int> &arr,int s,int e){

    int i = s-1;    // Index
    int pivot = arr[e];  // Element
     
    // j
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;

}

int quickselect(vector<int> arr,int s,int e,int k){

    int pivot = partition(arr,s,e);
    if(pivot==k){
        return arr[pivot];
    }

    else if(k<pivot){
        return quickselect(arr,s,pivot-1,k);
    }
    else{
        return quickselect(arr,pivot+1,e,k);
    }


}

int main(){

    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int k = 4;

    int n = arr.size();
    cout<<quickselect(arr,0,n-1,k);
    return 0;
}