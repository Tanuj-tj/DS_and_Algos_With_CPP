#include <bits/stdc++.h>

using namespace std;

void reverseArray(int arr[],int n){
    
    int s = 0; 
    int e = n - 1;
    
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    
}

int main()
{
    int arr[] = {10,20,30,40,45,60,70,89};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"Given Array : ";
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    
    reverseArray(arr,n);
    
    cout<<endl;
    cout<<"Reversed Array : ";
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

/*
O/P :
Given Array : 10 20 30 40 45 60 70 89 

Reversed Array : 89 70 60 45 40 30 20 10 


*/
