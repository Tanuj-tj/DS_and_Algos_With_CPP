#include<bits/stdc++.h>
using namespace std;

// partition the array with pivit in its correct location
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
void quick_sort(vector<int> &arr,int s,int e){
   
    // s = 0 and e = arr.size()-1
    // Base Case
    if(s>=e){
        return;
    }
    // Recursive Case
    int pivot = partition(arr,s,e);
    quick_sort(arr,s,pivot-1);
    quick_sort(arr,pivot+1,e);    
}

int main(){

    vector<int> arr = {10,5,2,0,7,6,4};
    int n = arr.size();

    quick_sort(arr,0,n-1);

    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}