/*
Slldlng Wlndow MaXImum 
----------------------

Given an array and an integer K, return a vector containing maximum for each and every
contiguous subarray of size k.

Sample Input :

K = 3
input = {1, 2, 3, 1, 4, 5, 2, 3, 6}

Sample Output :

output = {3,3,4,5,5,5,6}

*/


#include<bits/stdc++.h>
using namespace std;


vector<int> maxInWindow(vector<int> input,int k){

    // Keep track of Start and end of window
    
    int i=0,j=0;  // i = start of window and j = end of window  
    // increase j till the size of k
    
     vector<int> ans;

    int mx = INT_MIN;
    while(j<input.size()){    // O(N)

        mx = *max_element(input.begin()+i,input.begin()+j+1);   // O(K)

        if(j-i+1 < k){
            j++;
        }

        else if(j-i+1 == k){
            ans.push_back(mx);
            i++;j++;
        }
    }

    return ans;
  
}

int main(){
    
    vector<int> input = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    auto res = maxInWindow(input,k);
    for(auto i:res){
        cout<<i<<" ";
    }
    
    return 0;
}
