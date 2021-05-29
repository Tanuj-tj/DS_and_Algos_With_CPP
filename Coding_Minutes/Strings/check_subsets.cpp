/*
Given two non-empty strings, write a function that
determines whether the second string is subsequence of
first one.

Sample Input :

codingminutes
cines

Sample Output :
Yes

*/

#include<bits/stdc++.h>
using namespace std;

bool check(string s,string match){
    
    // 2 Pointers

    int i=s.length()-1 , j=match.length()-1;

    while(i>=0 and j >=0){
        if(match[j] == s[i]){
            i--;j--;
        }
        else{
            i--;
        }
    }

    if(j==-1) return true;
    else return false;
}

int main(){
    
    string s = "coding minutes";
    string match = "cines";

    cout<<check(s,match)<<endl;

    return 0;
}
