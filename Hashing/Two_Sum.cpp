// Optimize using hash table
//   => Unordered map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;   // store the resultant array
        unordered_map<int,int> mpp;    // value , index
        
        for(int i=0;i<nums.size();i++){   // Iterate
            if(mpp.find(target-nums[i]) != mpp.end()){  // check if target-nums[i] exist in the hash table or not
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;  // Store the current key as element and value as index in a map 
        }
        return ans; // in case no pair is found return an empty vector 
        
        
        
    }
};