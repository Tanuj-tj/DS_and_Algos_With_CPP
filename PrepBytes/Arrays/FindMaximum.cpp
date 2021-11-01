#include <bits/stdc++.h>
using namespace std;
  
void printArr(int * arr, int n){
  for(int i = 0 ; i < n ; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int findMax(int * arr,int n){
  
  int temp[n];
  temp[n-1] = arr[n-1];
  for(int i = n-2 ; i >= 0 ; i--){
    temp[i] = max(arr[i],temp[i+1]);
  }

  // Binary search to find the right most max index 

  int result = 0;
  for(int i = 0 ; i < n ; i++){
    int low = i+1, high = n-1, ans = i;
    
    while(low <= high){
      int mid = (low + high) / 2;

      if(arr[i] <= temp[mid]){
        ans = max(ans,mid);
        low = mid + 1;
      }
      else{
        high = mid - 1;
      }

    }

    result = max(result, ans - i);
  }

  return result;
}

int main()
{
  //write your code here
  
  int n; cin>>n;
  int arr[n];
  for(int i = 0 ; i < n ; i++) cin>>arr[i];
  
  int ans = findMax(arr,n);
  if(ans == 0){
    cout<<-1<<endl;
  }
  else{
    cout<<ans<<endl;
  }
    
  return 0;
}
