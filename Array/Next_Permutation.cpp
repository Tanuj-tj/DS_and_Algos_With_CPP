class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // Using Inbuilt function =>
        // next_permutation(nums.begin(),nums.end());
        // for(auto &i:nums){
        //     cout<<i;
        // }
        
        // Without inbuilt function 
        int n = nums.size(), k,l;
        
        for(k=n-2;k>=0;k--){  // O(N)
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
             for(l=n-1;l>=k;l--){
                if(nums[k]<nums[l]) break;
             }   
             swap(nums[k],nums[l]);
             reverse(nums.begin()+k+1,nums.end());
        }
    }
};
