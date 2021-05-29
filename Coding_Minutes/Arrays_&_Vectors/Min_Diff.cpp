/*
Implement a function that takes in two non-empty arrays of integers, finds the pair of numbers
(one from each array) who absolute difference is closest to zero, and returns a pair containing
these two numbers, with the first number from array. Only one such pair will exist for the test.

Input :

Arrayl = [23, 5, 1a, 17, 3a]

Array2 = [26, 134, 135, 14, 19]

Output :
17,19

*/

#include<bits/stdc++.h>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    
    int min_val = INT_MAX;
    pair<int,int> p;
    // O(N^2)
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            int check = abs(a[i]-b[j]); 
            if(check < min_val){
                min_val = check;
                p.first = a[i];
                p.second = b[j];
            }
        }
    }
    
    return p;
    
}
