class Solution {
public:
    
    // Optimized Soltion => O(N^3)
    // Using 2Sum + i and j pointers
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //2d array to return the ans
        vector<vector<int>> ans;
        
        // Empty Check
        if(nums.empty()) return ans;
        
        // Sort 
        sort(nums.begin(),nums.end());
        
        // 2 nested for loops for i and j pointers
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                
                // 2 Pointers
                int front = j+1;
                int back = nums.size()-1;
                
                int target_2 = target - nums[j] - nums[i];
                
                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    
                    if(two_sum > target_2) back--;
                    else if(two_sum < target_2) front++;
                    
                    else{
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[front];
                        temp[3] = nums[back];
                        ans.push_back(temp);
                        
                        // Check for duplicates
                        while(front < back && nums[front]==temp[2]) ++front;
                        while(front < back && nums[back]==temp[3]) --back;
                    }
                }
                while( j+1 < nums.size() && nums[j+1]==nums[j] ) ++j;
            }
            while( i+1 < nums.size() && nums[i+1]==nums[i]) ++i;
        }
        return ans;
        
    }
};
