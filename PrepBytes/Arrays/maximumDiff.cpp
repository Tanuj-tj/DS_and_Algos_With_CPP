#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll maxDiff(ll *arr,ll n){
    ll max1 = INT_MIN, max2 = INT_MIN;
    ll min1 = INT_MAX , min2 = INT_MAX;
    
    for(ll i = 0 ; i < n ; i++){
        max1 = max(max1, arr[i]+i);
        max2 = max(max2, arr[i]-i);
        min1 = min(min1, arr[i]+i);
        min2 = min(min2, arr[i]-i);
    }
    
    return max((max1-min1),(max2-min2));
}
  
int main()
{
  //write your code here
  int t;cin>>t;
  while(t--){
    ll n; //cin>>n;
    scanf("%lli",&n);
    ll arr[n];
    for(ll i = 0 ; i < n ; i++) scanf("%lli",&arr[i]);//cin>>arr[i];
    
    cout<<maxDiff(arr,n)<<endl;  
    
  }
  
  return 0;
}
