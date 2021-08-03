#include <bits/stdc++.h>

using namespace std;

// O(LogN)
int binary_search(int arr[],int n,int key){
    
    int s = 0;
    int e = n-1;
    int mid;
    
    while(s<=e){
        mid = (s + e)/2;
        
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    
    return -1;
    
}

int main()
{
    int arr[] = {10,20,30,40,45,60,70,89};
    int n = sizeof(arr)/sizeof(int);
    
    int k; cin>>k;
    
    int index = binary_search(arr,n,k);

    if(index==-1){
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"key found at index : "<<index<<endl;
    }
    return 0;
}
