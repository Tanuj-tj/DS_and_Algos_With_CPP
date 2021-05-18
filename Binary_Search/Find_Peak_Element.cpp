class Solution {
public:
    
    // Binary Search
    int BS(vector<int>& nums,int start,int end){
        
        if(start==end) return start;
        
        int mid = (start+end)/2;
        
        int L = BS(nums,start,mid);
        int U = BS(nums,mid+1,end);
        
        if(nums[L]>=nums[U]) return L;
        else return U;
    }
    int findPeakElement(vector<int>& nums) {
        int start = 0,end = nums.size()-1;
        return BS(nums,start,end);
    }
};
