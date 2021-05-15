
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


// -------------------------------------------------------------------------------------------------------------
class Solution {
public:
    
    // Bahut Jeda Bruit Force Appraoch 
    // O(N^4 + NlogN + N)  // Still Passed : 189 / 283 Test Cases
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            
    vector<vector<int>> ans;
 
        for(int i=0;i<nums.size();i++){
            
            for(int j=i+1;j<nums.size();j++){
                
                for(int k=j+1;k<nums.size();k++){
                    
                    for(int l=k+1;l<nums.size();l++){
                        vector<int> curr_sum;
                        if( nums[i]+nums[j]+nums[k]+nums[l] == target){
                            curr_sum.push_back(nums[i]);
                            curr_sum.push_back(nums[j]);
                            curr_sum.push_back(nums[k]);
                            curr_sum.push_back(nums[l]);
                            ans.push_back(curr_sum);
                        }
                    }
                }
            }
        }
        
    // Get the uinque combination 
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
    return ans;
        
    }
};
