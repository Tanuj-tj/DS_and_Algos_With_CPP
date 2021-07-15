/* HEAP  */


#include <bits/stdc++.h>

using namespace std;

void swap(int arr[],int n,int parent,int i){
    int temp = arr[parent];
    arr[parent] = arr[i];
    arr[i] = temp;
}

void insert(int arr[],int n,int value){
    n = n + 1;
    arr[n] = value;
    int i = n;
    
    while(i > 1){
        int parent = i / 2;
        if(arr[parent] < arr[i]){
            swap(arr,n,parent,i);
            i = parent;
        }
        else{
            return;
        }
    }
}

int main()
{
    int n = 7;
    int arr[n] = {50,40,45,30,20,35,10};
    
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    insert(arr,n,60);

    for(int i = 0 ; i < n+2 ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
