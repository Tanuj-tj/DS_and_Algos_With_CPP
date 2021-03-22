#include<iostream>
using namespace std;

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main(){

    int arr[] = {4,3,7,1,5};
    int n = 5;
    
    bool swapped = true;
    for(int i=0;i<n;i++){                      
        for(int j=0;j<n-i-1;j++){
           swapped = false;
           if(arr[j+1]<arr[j])
                swap(arr,j+1,j);
        }
        if(swapped)
            break;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
