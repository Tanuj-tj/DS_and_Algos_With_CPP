/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

*/

/* Bruit Force : O(N^2) */

 int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        
        int n = nums.size();
                
        for(int i = 0 ; i < n ; i++){
            
            int sum = 0;

            for(int j = i ; j < n ; j++){
            
                sum+=nums[j];
                if(sum==k) count++;
            }   
        }
        return count;
 }

/* Prefix Sum + Unordered map */

int subarraySum(vector<int>& nums, int k) {
        
        int count = 0, sum = 0;
        
        int n = nums.size();
    
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++){
            sum+=nums[i];
            if(sum==k) count++;
            if(mp.find(sum-k)!=mp.end()) count+=mp[sum-k];
            mp[sum]++;
        }
        
        return count;
    }





