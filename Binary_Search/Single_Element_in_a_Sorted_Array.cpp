class Solution {
public:
    // Approach 1: XOR Operation => O(N)
    // int singleNonDuplicate(vector<int>& nums) {
    //     int ans=nums[0];
    //     for(int i=1;i<nums.size();i++){
    //         ans^=nums[i];
    //     }
    //     return ans;
    // }
    
    // Approach 2 : Binary Search => O(logN)
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0,high = nums.size()-1, mid;
        
        // Corner Cases
        if(high==0) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[high]!=nums[high-1]) return nums[high];
        
        while(low<=high){
            
            mid = (high+low)/2;
            
            // if mid is the unique el
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            
            // if el is at the left of mid
            if( mid%2==0 && nums[mid]==nums[mid+1]  || mid%2!=0 && nums[mid]==nums[mid-1] ){
                low = mid - 1;
            }
            // if el is at the right of mid
            else{
                high = mid + 1;
            }
                    
        }
        
        return -1;
    }
};
