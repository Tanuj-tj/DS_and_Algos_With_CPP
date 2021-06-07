/*
Finding Subsets
===============

Given a string, find all subsets of the given string.
Input :
abc

Output :
"",a,b,c,ab,ac,bc,abc 

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


// O(2^N)
void solve(string s,int i,string ans) {

   // Base Case
   if(i == s.length()){
       cout<<ans<<" ";
       return;
   } 

   // Include
   solve(s,i+1,ans+s[i]);
   // Not Include
   solve(s,i+1,ans);

}

int main(){
  
    string s = "abc";
    int i = 0;
    solve(s,i,"");
	return 0;
}