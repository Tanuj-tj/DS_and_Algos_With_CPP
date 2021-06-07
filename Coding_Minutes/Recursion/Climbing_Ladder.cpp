/*
Climbing Ladder
==============

Given a ladder containing N Steps, you can take a jump of 
1,2 or 3 at each step. Find the number of ways to climb the ladden

Sample input :
N = 4

Sample Output :
7
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


// O(3^N)
int solve(int N) {

    // Base Case
    if(N==0 ) return 1;
    if(N<0) return 0;
   
    // Recursive case
    return solve(N-1) + solve(N-2) + solve(N-3);
}

// o(N^2)
int solveDP(int N,vi &dp) {
    if(N==0 ) return 1;
    if(N<0) return 0;
    if(dp[N]!=0) return dp[N];
     
    dp[N] = solveDP(N-1,dp) + solveDP(N-2,dp) + solveDP(N-3,dp);

    return dp[N];
}

int main(){
  
    int N = 4;
    cout<<solve(N)<<endl; 
    
    vi dp(N+1,0);
    cout<<solveDP(N,dp);
	return 0;
}