/*
Steps :
1. Create an unordered set and put all the elements into it
2. check for every ith element if nums[i]-1 does not exis in set
3  If not then keep count = 1 and check for every nums[i]+1 element inside set 
    - if present then count++
    - keep track of maxCount 
*/

class Solution {
public:
    
    // Complexity : O(N) + O(N) + O(N)
    int longestConsecutive(vector<int>& nums) {
        
        // Create a set
        unordered_set<int> st;
        
        // Push the elements into set
        for(int i:nums){
            st.insert(i);    
        }
        
        int ans = 0;
        for(int i:nums){
            if(!st.count(i-1)){
                int currNum = i;
                int currCount = 1;
                
                while(st.count(currNum+1)){
                    currNum += 1;
                    currCount += 1;
                }
                
                ans = max(currCount,ans);
            }
        }
        
        return ans;
        
    }
};
