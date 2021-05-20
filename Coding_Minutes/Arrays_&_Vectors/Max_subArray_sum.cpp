#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    
    int mx = 0;
    int curr_mx = 0;
    
    for(int i=0;i<n;i++){
        curr_mx = max(curr_mx+arr[i], arr[i]);
        if(curr_mx < 0) curr_mx = 0;
        mx = max(curr_mx,mx);
    }
    
    return mx;
    
    
    
}
