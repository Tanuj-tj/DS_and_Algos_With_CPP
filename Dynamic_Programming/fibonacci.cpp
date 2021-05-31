#include<bits/stdc++.h>
using namespace std;

class Fibonacci{
    public:

    // Fibonacci Series with recursion  : TC = O(2^N)  SC = O(N)
    int fib_rec(int n){ 
        // Base Case
        if(n==1 || n==0){
            return n;
        }
        return fib_rec(n-1) + fib_rec(n-2);
    }

    // Top Down DP  : TC = O(N)  SC = O(N + N)
    int fib_TopDownDP(int n,vector<int> &dp){
        // Base Case
        if(n==1 || n==0){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = fib_TopDownDP(n-1,dp) + fib_TopDownDP(n-2,dp);
        return dp[n];
    }

    // Bottom Up DP  : : TC = O(N)  SC = O(N)
    int fib_BottomUpDP(int n){
        // Base Case
        if(n==1 || n==0){
            return n;
        }

        // Local Dp array
        vector<int> dp(n+1,-1);

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

};

int main(){
    int n = 6;
    Fibonacci *obj = new Fibonacci();

    cout<<obj->fib_rec(n)<<endl;
    vector<int> dp(n+1,-1);
    cout<<obj->fib_TopDownDP(n,dp)<<endl;
    cout<<obj->fib_BottomUpDP(n)<<endl;
}
