#include <bits/stdc++.h>

using namespace std;

// O(N)
int linear_search(int arr[],int n,int key){
    
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==key){
            return i;
        }
    }
    
    return -1;
}

int main()
{
    int arr[] = {10,22,4,2,4,12};
    int n = sizeof(arr)/sizeof(int);
    
    int k; cin>>k;
    
    int index = linear_search(arr,n,k);

    if(index==-1){
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"key found at index : "<<index<<endl;
    }
    return 0;
}
