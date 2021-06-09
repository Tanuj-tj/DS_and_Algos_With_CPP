/*

Generating Brackets
===================

Write a function to generate all possible n pairs of balanced parentheses '(' and ')'

Input :
2 

Output :
()()
(())


*/


#include<bits/stdc++.h>
using namespace std;


void solve(int n, string output, int open,int close ,int i) {
    
    // Base Case
    if(i==2*n){
        cout<<output<<endl;
        return;
    }

    if(open < n){
        solve(n,output+"(",open+1,close,i+1);        
    }
    if(close<open){
        solve(n,output+")",open,close+1,i+1);
    }
    
}

int main(){
    
    int n = 3;
    string output;
    solve(n,output,0,0,0);   // 0 => index , 0 => Opening Brackers, 0 => Closing Brackets
	return 0;
}