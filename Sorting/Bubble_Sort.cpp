#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Bubble_sort(int arr[],int n){
    bool swapped = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            swapped = false;
            swap(arr,j+1,j)
        }
        if(!swapped){
            break;
        }
    }
}
int main(){

    int arr[] = {4,3,7,1,5};
    int n = 5;
    cout<<Bubble_sort(arr,n)<<endl;

    return 0;
}