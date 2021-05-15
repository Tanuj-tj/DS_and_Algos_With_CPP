class Solution {
public:
    
    // Complexity : O(N) + O(N) + O(N)
    int longestConsecutive(vector<int>& nums) {
        
        // Create a set
        set<int> st;
        
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
