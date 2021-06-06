/*
Given a number x we can do 3 differnet operations on x
1. Substract 1 from x
2. If x is divisible by 2 then divide by 3
3. If x is divisible by 3 then divide by 3

Recuerence :

f(x) = 1 + min(f(x-1) , f(x/2) , f(x/3) ) 

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define F first
#define S second
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;


// Top Down DP
ll minStepsToOneTD(int x,vll &dp) {
    
    // Base cases
    if(x==2 or x==3){
        return 1; 
    }   
    if(x == 1){
        return 0;
    }
    if(x < 1){
        return INT_MAX;
    }
    if(dp[x]!=0){
        return dp[x];
    }

    ll div_by_3 = INT_MAX;
    ll div_by_2 = INT_MAX;
    ll sub_by_1 = INT_MAX;

    if(x % 3 == 0){
        div_by_3 = 1 + minStepsToOneTD(x/3,dp);
    }
    if(x % 2 == 0){
        div_by_2 = 1 + minStepsToOneTD(x/2,dp);
    }
    sub_by_1 = 1 + minStepsToOneTD(x-1,dp);

    return dp[x] = min({ div_by_3, div_by_2, sub_by_1 });

}

// BottomUp DP
ll minStepsToOneBU(int x){

    vll dp(x+1,0);
    dp[0] = INT_MAX;
    dp[1] = 0;
    dp[2] = dp[3] = 1;

    for(int i=4;i<=x;i++){
        ll div_by_3 = INT_MAX;
        ll div_by_2 = INT_MAX;
        ll sub_by_1 = INT_MAX;

        if(i % 3 == 0){
            div_by_3 = 1 + dp[i/3];
        }

        if(i % 2 == 0){
            div_by_2 = 1 + dp[i/2];
        }
        sub_by_1 = 1 + dp[i-1];

        dp[i] = min({ div_by_3, div_by_2, sub_by_1 });

    }

    return dp[x];
}

int main(){
  
    int x = 7;

    // Top Down DP
    //ll *dp = new ll(x+1);
    vll dp(x+1,0);  
    cout<< minStepsToOneTD(x,dp)<<endl;

    // BottomUp DP
    cout<<minStepsToOneBU(x)<<endl;
	return 0;
}