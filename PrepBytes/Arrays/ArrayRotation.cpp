#include <bits/stdc++.h>
#define lli long long int
using namespace std;
  
void printArray(int *arr,int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *arr,int a,int b){
    int temp = arr[a];
    arr[a]  = arr[b];
    arr[b] = temp;
}

void reverse(int *arr,int start,int end){
    int n = (start + end) / 2;
    while(start <= end){
        swap(arr,start++,end--);
    }
}

void reversal_Algo(int *arr,int n,int d){
    reverse(arr,0,n-d-1);
    reverse(arr,n-d,n-1);
    reverse(arr,0,n-1);

    printArray(arr,n);
}

void rotate_inplace(int *arr,int n,int d){
    
    int j = d;
    for(int i = 0 ; i < n-1 ; i++){
        swap(arr,i,j++);
    }
    printArray(arr,n);
}

void rotate_with_extra_space(int *arr,int n,int d){
    
    int temp[d];
    for(int i = 0 ; i < d ; i++){
        temp[i] = arr[i];
    }
    
    for(int i = 0 ; i < n-d ; i++){
        arr[i] = arr[d+i];
    }
    
    int j = n-d;

    for(int i = 0 ; i < d ; i++){
        arr[j++] = temp[i]; 
    }
    
    printArray(arr,n);
    
}
  
int main()
{
    //write your code here
    int n,d; cin>>n>>d;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    
    if(k > n){
      k = k % n;
    }
  
    // rotate_with_extra_space(arr,n,d);
     rotate_inplace(arr,n,d);
    //reversal_Algo(arr,n,d);
    
    return 0;
  }
