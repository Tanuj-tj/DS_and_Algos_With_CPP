#include <bits/stdc++.h>
using namespace std;
  
int slidingWindow(int *arr,int n,int k){
  
  // Step 1 : Sum of first k elements
  
  int max_window = INT_MIN, sum = 0;
  
  for(int i = 0 ; i < k ; i++){
      sum += arr[i];
  }
  max_window = sum;

  // Step 2 : Add the ith element and remove the k-ith element 

  for(int i = k ; i < n ; i++){
    sum += arr[i] - arr[i-k];
    max_window = max(max_window, sum);
  }

  return max_window;
}

int main()
{
  //write your code here
  int n,k;cin>>n>>k;
  int arr[n];
  for(int i = 0 ; i < n ; i++) cin>>arr[i];
  cout<<slidingWindow(arr,n,k)<<endl;
  
  return 0;
}