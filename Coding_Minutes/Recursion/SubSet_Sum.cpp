/*
Subset Sum
==========

Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum
equal to given sum. 

Input :
arr=[10,12,15,6,19,20]
sum = 16

Output :
Yes

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 1e18
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>
#define all(n) n.begin(),n.end()
#define mid(l,r) (l+(r-l)/2)
#define F first
#define S second
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

// Recursive
int solve(vi arr,int n,int sum,int i) {
   
   // Base case
   if(i==n){
       if(sum==0){
           return 1;
       }
       return 0;
   }

   int inc =  solve(arr,n,sum - arr[i],i+1);
   int exc = solve(arr,n,sum,i+1);

   return inc + exc; 

}

// DP TopDown
int solveDPTD(vi arr,int n,int sum,int i,vi dp) {
   
   // Base case
   if(i==n){
       if(sum==0){
           return 1;
       }
       return 0;
   }

   if(dp[i]!=0) return dp[i];

   int inc =  solveDPTD(arr,n,sum - arr[i],i+1,dp);
   int exc = solveDPTD(arr,n,sum,i+1,dp);

   dp[i] =  inc + exc;

   return dp[i]; 

}

int main(){
    
    vi arr{10,12,15,6,19,20};
    int sum = 16;
    vi arr1{1,2,3,4,5};
    int sum1 = 6;
    
    cout<<solve(arr,arr.size(),sum,0)<<endl;
    cout<<solve(arr1,arr1.size(),sum1,0)<<endl;

    vi dp(arr.size(),0);
    cout<<solveDPTD(arr1,arr1.size(),sum1,0,dp)<<endl;
    
	return 0;
}