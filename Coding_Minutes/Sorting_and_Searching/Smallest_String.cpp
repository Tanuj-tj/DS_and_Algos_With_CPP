/*
Smallest String
---------------

You're given a list of n strings a1,a2,...,an. You'd like to
concatenate them together In some order such that the
resulting string would be lexicographically smallest.
Given the list of strings, output the lexicographically
smallest concatenation.

Input :

3
c
cb
cba

Output :

cbacbc

Input :

3 
a
ab
aba

Output :

aabaab

*/

/*
Apporaches :

1. To generate every possible combination we have N! ways for N no. of strings 
   which is not a very practical approach .

2. Sorting - Not direct sorting check every element whether it will come first or 
   it will come second .
    - We need a custom comparator function for this case .
*/

#include<bits/stdc++.h>
using namespace std;

bool compare(string s1,string s2){
    return s1+s2 < s2+s1;
}

int main(){
   
    string s[] = {"a","ab","aba"};
    int n = 3;

    sort(s,s+n,compare);

    for(auto i:s){
        cout<<i;
    }

    return 0;
}