/*
You are given a string, you need to print all Eubsequences
of the string sorted by length and lexicographic sorted
order if length is same.

Sample Input :
abcd
Sample Output :
,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd,
*/

#include<bits/stdc++.h>
using namespace std;

// RECURSION :
// 2 options
// Either include a char in a subsequence
// or not include it

// Global vector to store the resultant subsequences
vector<string> v;

void check(string s, string out){
    
    // Base case
    if(s.size()==0){
        v.push_back(out);
        return;
    } 

    // Recursive case
    char ch = s[0];   // a
    string reduced_input = s.substr(1); // bc

    // Includes
    check(reduced_input,out+ch);

    // Exclude
    check(reduced_input,out);

}

bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length(); 
}

int main(){
    
    string s;
    cin>>s;
    string output = " ";
    check(s,output);

    sort(v.begin(),v.end(),compare);

    for(auto &i:v){
        cout<<i<<" ";
    }

    return 0;
}
