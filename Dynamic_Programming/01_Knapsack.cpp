// Steps  :
// 1. Base Constion
// 2. Choice Diagram

/*
Choice Diagram :
--------------

    Item(w1)
       /  \
      /    \
w1 <= w     w1 > w
    / \      |
   /   \     |
  Yes  No    No

*/


#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>

// Recursive Soution  TC : O(2^N) , SC : O(1)
int ZeroOne_knapsack_Rec(int W, vi wt, vi val,int n) {

    // Base case
    // If no items in the knapsack then no profit`
    if(n == 0 or W == 0 ){
        return 0;
    }

    if(wt[n-1] <= W){
        return max( val[n-1] + ZeroOne_knapsack_Rec( W-wt[n-1],wt,val,n-1 ) , ZeroOne_knapsack_Rec( W,wt,val,n-1 )   );  

    }

    else if(wt[n-1] > W){
        return ZeroOne_knapsack_Rec(W,wt,val,n-1);
    }
    
}

// Top Down DP  TC :

// DP array filled with -1

int dp[1000][1000];

int ZeroOne_knapsack_TDDP(int W, vi wt, vi val,int n) {

    // Base case
    // If no items in the knapsack then no profit`
    if(n == 0 or W == 0 ){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(wt[n-1] <= W){
        return dp[n][W] = max( val[n-1] + ZeroOne_knapsack_TDDP( W-wt[n-1],wt,val,n-1 ) , ZeroOne_knapsack_TDDP( W,wt,val,n-1 )   );  

    }

    else if(wt[n-1] > W){
        return  dp[n][W] =  ZeroOne_knapsack_TDDP(W,wt,val,n-1 );
    }
    
}


int main(){
  
    vi val{ 60, 100, 120 };
    vi wt{ 10, 20, 30 };
    int W = 50;
    int n = val.size();
    cout<<ZeroOne_knapsack_Rec(W,wt,val,n)<<endl;
    
    // DP array filled with -1
    // vii dp(n+1, vi(wt.size()+1,-1));
    memset(dp,-1,sizeof(dp));
    cout<<ZeroOne_knapsack_TDDP(W,wt,val,n)<<endl;
	return 0;
}