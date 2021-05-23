#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
#define fo(i,n) for(i=0;i<n;i++)
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

//Global Dp array
//  db[n][k][first]

int dp[105][105][2];

int f(int n,int k,int first){

	if(n==0) return 0;
	if(n==1){
		if(k==0) return 1;
		else return 0;
	}
    if(dp[n][k][first] != -1){
    	return dp[n][k][first];
    }
    int result = -1;
    if(first==1){
    	result = f(n-1,k,0) + f(n-1,k-1,1);
    }
    // first==0
    else{
    	result = f(n-1,k,0) + f(n-1,k,1);
    }	

    return dp[n][k][first] = result;
   
}

int main(){
  
    // Test Cases
    int T;cin>>T;
    while(T--){
        int num;cin>>num;
        int n;cin>>n;
        int k;cin>>k;
    
        // Initialize dp array with -1
        memset(dp, -1, sizeof(dp));
  
        // f(n,k,0) + f(n,k,1)
        int ans = f(n,k,0);
        ans += f(n,k,1);

        cout<<num<<" "<<ans<<endl;
    }
	return 0;
}