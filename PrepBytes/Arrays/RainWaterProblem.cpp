#include <bits/stdc++.h>
#define lli long long int
using namespace std;
  
int rainWater(int *arr, int n){

    int left[n],right[n];
    int area = 0;

    left[0] = arr[0];
    right[n-1] = arr[n-1];
 
    for(int i = 1 ; i < n ; i++){
        left[i] = max(left[i-1], arr[i]);
        right[n-i-1] = max(right[n-i] , arr[n-i]);
    }
    
    for(int i = 0 ; i < n ; i++){
        area += ( min(left[i],right[i]) - arr[i]) ;
    }
    return area;
}
  
int main()
{
 //write your code here
    int n; cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    cout<<rainWater(arr,n)<<endl;
    
    return 0;
  }