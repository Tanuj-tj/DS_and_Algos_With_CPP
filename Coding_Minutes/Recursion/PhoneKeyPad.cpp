/*
Phone Keypad
============

Given a number N and a modern phone keypad. Find out all possible
strings generated using the number

Sample Input :
23

Sample Output :
AD, AE,AF, BD,BE,BF,CD,CE,CF

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

// Key Pad         0   1   2     3     4     5     6      7     8     9
string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


void solve(string input,string ans,int i=0) {
    
    // Base Base input[i] is a null string
    if(input[i]=='\0'){
        cout<<ans<<endl;
        return;
    }
    
    // Convert the input string into integer
    int current_digit = input[i]-'0';

    // If 0 or 1 is passes
    if(current_digit == 1 or current_digit == 0){
        return solve(input,ans,i+1);
    }  

    for(int k=0;k<keypad[current_digit].size();k++){
        solve(input,ans+keypad[current_digit][k],i+1);
    }
    
    return;
}

int main(){
  
    string input = "23";
    string ans;
    solve(input,ans);
	return 0;
}
