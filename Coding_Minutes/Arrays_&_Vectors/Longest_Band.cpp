/*
Given an array containing N integers, find length of longest band.

A band is defined as a subsequence which can be re- ordered in such a manner all elements appear
consecutive (ie with absolute difference of1 between neighbouring elements)

A longest band is the band (subsequence) which contains maximum integers.
*/


// Approach :
// 1. Sort + Traverse => O(NlogN + N)
// 2. Maintain a unordered_set O(1) + traverse and check O(N)

#include<bits/stdc++.h>
using namespace std;

int Longest_Band(vector<int> &arr){
    
    int n = arr.size();

    // Push the elements in set
    unordered_set<int> s;
    for(int i:arr) s.insert(i);
    
    // Maintain a max count
    int max_count = 0;
    // Traverse through arr 
    for(auto i:arr){
        // Check if a smaller elemet then ith element present in set
        if(s.find(i-1) == s.end()){
            int curr_count = 1;
            int j = i;
            while(j<=n and s.find(j+1) != s.end()){
                curr_count++;
                j++;
            }
            // Check the max_count after every chain
            max_count = max(max_count , curr_count);
        }
    }
    return max_count;
}

int main(){
    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<Longest_Band(arr)<<endl;

    return 0;
}
