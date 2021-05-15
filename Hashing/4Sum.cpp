



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
