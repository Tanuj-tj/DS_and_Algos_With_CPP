#include <iostream>

using namespace std;

int binary_search(int arr[],int n,int l,int h,int key){    // T(n)
    if(l==h){
        if(arr[l]==key)
            return l;
        else
            return 0;
       
    }
    
    else{
        
        int mid = (l + h)/2;          // 1
                   
        if(key ==arr[mid])           // 1        
            return mid;
        if(key<arr[mid])             // 1
            return binary_search(arr,n,l,mid-1,key);     // T(n/2)
        else
            return binary_search(arr,n,mid+1,h,key);

        
    }
}

int main()
{
    int n = 8,key = 6; 
    int arr[n] = {1,2,3,4,5,6,7,8};
    cout<<binary_search(arr,n,0,n-1,key);

    return 0;
}
