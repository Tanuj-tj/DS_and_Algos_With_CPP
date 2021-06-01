/*
Problem :
--------

You are given money present in adjacent houses . There is a robber who wnats to
rob the houses but he can never rob from 2 adjacent houses . Find max loot of robber .

Input : [2,7,9,3,1] , n = 5
Op : 12
*/

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int

// Top Down
ll lootHouse_TD(vi &arr, vi &dp,int i){
    // Base cases
    if(i==0){
        return dp[0] = arr[0];
    }
    if(i==1){
        return dp[1] = max(arr[0],arr[1]);
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    return max(lootHouse_TD(arr,dp,i-1), lootHouse_TD(arr, dp,i-2)+arr[i]);
}


// Bottom Up
ll lootHouse_BU(int n, vi &arr){

    // Dp array initiallize with 0
    vi dp(n,0);

    // Initial conditions
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);

    for(int i=2;i<=n;i++){
        dp[i] = max(arr[i] + dp[i-2] ,dp[i-1]);
    }
    return dp[n-1];

}

int main(){

int n = 5;
vi arr = {2,7,9,3,1};
cout<<lootHouse_BU(n,arr)<<endl;

vi dp(n,-1);
cout<<lootHouse_TD(arr,dp,n-1)<<endl;


}

