/*
Sorted Permutations
===================

Given a string S of lowercase alphabets, you need to find all 'unique' permutations of the string
in a 'Sorted' order.

(Hint: You can use find all permutations using brute force, and put them in a set for the sorting.)

Input Format:
Functions contains string S as a parameter.(There are more than 1 testcases).

Output Format:
Return a sorted vector containing all the permutations of string.

Constraints:
1<:S.Length<:1O

Sample Testcase:

Input
acb

Output:
abc
acb
bac
bca
cab
cba



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

// will store the result
vs ans;
set<string> order;

// Swap
void swap(string &s,int i,int l){
    char temp = s[i];
    s[i] = s[l];
    s[l] = temp;
}


// Solve
void solve(string &s,int l,int h){

    // Base Case
    if(l==h){
        ans.push_back(s);
        return;
    }

    for(int i=l;i<h;i++){

        swap(s,i,l);
        solve(s,l+1,h);
        swap(s,i,l);
    }
}

vector<string> findSortedPermutations(string s){
    
    // clear the vector and set for every test case
    ans.clear();
    order.clear();

    solve(s,0,s.length());
    
    for(auto i:ans){
        order.insert(i);
    } 

    ans.clear();
   
    for(auto i:order){
        ans.push_back(i);
    }

    return ans;
    
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
}


int main(){
     
    string s = "abc";

    auto res = findSortedPermutations(s);

    for(auto i:res){
        cout<<i<<" ";
    }
    
	return 0;
}