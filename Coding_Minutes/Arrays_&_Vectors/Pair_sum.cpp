/*
Approaches :
1. Bruit Force using nested loop : O(N^2)
2. Optimized Using Sorting + Binary Search : O(NLogN)
3. Best using Unorder Set : O(N) 
*/

#include<bits/stdc++.h>
using namespace std;

//Complete this method, don't write main
vector<int> Pair_sum(vector<int> &arr,int target){
    unordered_set<int> s;
    vector<int> ans;
    
    for(int i:arr){
        int diff = target - i;
        if(s.find(diff) != s.end()){
            ans.push_back(i);
            ans.push_back(diff);
            return ans;
        }
        s.insert(i);
    }

    return {};
}

int main(){
    int target = 4;
    vector<int> arr = {10,5,2,3,-6,9,11};
    vector<int> ans = Pair_sum(arr,4); 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}