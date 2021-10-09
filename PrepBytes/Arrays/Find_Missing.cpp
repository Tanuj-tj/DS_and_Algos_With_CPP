#include <bits/stdc++.h>
  using namespace std;
  
  int main()
  {
    //write your code here
    int t;cin>>t;
    while(t--){
      long long n;cin>>n;
      long long arr[n-1];
      for(long long i = 0 ; i < n-1 ; i++ ){
        cin>>arr[i];
      }

      // Sum of n natural numbers 
      long long total = (n * (n + 1))/2;
      long long sum = 0;
      for(long long i = 0 ; i < n-1 ; i++){
        sum +=arr[i];
      }   
      cout<<(total - sum)<<endl;
    }
    
    return 0;
  }