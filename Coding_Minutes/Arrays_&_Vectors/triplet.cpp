/*
Given an array containing N integers, and an number S denoting a target sum.

Find all distinct integers that can add up to form target
sum. The numbers in each triplet should be ordered in
ascending order, and triplets should be ordered too.
Return empty array if no such triplet exists.

Input

array=[1, 2, 3, 4, 5, 6, 7, 8, 9,15]
target=18

Output

[[1, 2, 15],

[3, 7, 8]

[4, 6, 8]

[5, 6, 7]]

*/

/*
Approaches :
1. Bruit Force using nested loop : O(N^2)
2. Sort + 2 Pointers = O(NLogN) + O(N^2) => o(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

//Complete this method, don't write main
vector<vector<int>> triplet(vector<int> &arr,int target){

    // Sort
    sort(arr.begin(),arr.end());
    
    int n = arr.size();
    vector<vector<int>> ans;
    
   
    for(int i=0;i<=n-3;i++){

        int j = i+1;
        int k = n-1;

        // Two Pointer

        while(j<k){
            int curr_sum = arr[i];
            curr_sum += arr[j];
            curr_sum += arr[k];

            if(curr_sum==target){
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;k--;
            }
            else if(curr_sum > target) k--;
            else j++;
        }
    }

    return ans;
}

int main(){
    int target = 4;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    auto ans = triplet(arr,18); 
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
