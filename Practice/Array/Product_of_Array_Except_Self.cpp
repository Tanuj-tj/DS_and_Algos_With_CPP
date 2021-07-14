class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n);  // [_,_,_,_]
        
        vector<int> right(n+1); // [1,_,_,_,_]
        vector<int> left(n+1);  // [_,_,_,_,1]
        
        right[0] = 1;
        left[n] = 1;
        
        for(int i = 1 ; i <= n ; i++){
            right[i] = right[i-1] * nums[i-1];   // [1,1,2,6,12]
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            left[i] = left[i+1] * nums[i];   // [24,24,12,4,1]
        }
        
        for(int i = 0 ; i < n ; i++){
            ans[i] = right[i] * left[i+1];  // [24,12,8,6]
        }
        
        return ans;
    }
};

/*
Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/
