/*
Sortrng Subarray
-----------------

Write a function that takes in an array and returns two integers, denoting starting and ending
indices of the smallest subarray in the input array that needs to be sorted in place so that the
entire input is sorted.
If the input array is already sorted, return a pair [—1,-1].

Sample Input :
[0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29]

Sample Output :
[4,6]
*/

#include<bits/stdc++.h>
using namespace std;

// Helper function to check the element is placed at right loc or not
bool checkLoc(vector<int> &a,int i){
    // If i = 0
    
    if(i==0){
        return a[i] > a[i+1];
    }

    // If i = n-1;
    if(i==a.size()-1){
        return a[i] < a[i-1];
    }

    return a[i] > a[i+1] or a[i] < a[i-1];
}


pair<int,int> subarraySorting(vector<int> a){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
   
    int n = a.size();

    int small = INT_MAX;
    int large = INT_MIN;

    // Traverse through array O(N)
    for(int i=0;i<n;i++){

        // if True
        if(checkLoc(a,i)){
            small = min(small,a[i]); 
            large = max(large,a[i]);
        }
    }

    if(small==INT_MAX){
        return {-1,-1};
    }

    int left = 0;
    while(a[left]<=small) left++;
    
    int right = n-1;
    while(a[right]>=large) right--;

    return {left,right};

    
}
int main(){

    vector<int> a = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};

    auto ans = subarraySorting(a);

    cout<<ans.first<<" "<<ans.second;
}