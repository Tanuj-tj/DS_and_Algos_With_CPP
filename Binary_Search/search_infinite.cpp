#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int low,int high,int key){
    if (high>=low)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binary_search(arr, low, mid-1, key);
        return binary_search(arr, mid+1, high, key);
    }
    return -1;
}

int search_infinite(int arr[],int key){
    int low = 0;
    int high = 1;
    while(arr[high]<key){
        low = high;
        high = 2 * high;
    }
    return binary_search(arr,low,high,key);
}



int main(){
    int n=11,key = 140;
    int arr[n] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    cout<<search_infinite(arr,key)<<endl;

    return 0;
}
