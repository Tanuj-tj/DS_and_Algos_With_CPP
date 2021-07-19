class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        /* 1st way : Use inbuilt function
         next_permutation(nums.begin(),nums.end()); */
        
        /* 2nd way without using inbuilt function
          Steps :
          1. Traverse from back with variable i 
             Condition -> nums[i] < nums[i+1] 
          2. Again Traverse from Back with variable j 
             Condition -> nums[j] > nums[i]
          3. Swap the position of nums[i] and nums[j]
             -> swap(nums[i],nums[j])
          4. Reverse from i+1 index to n-1

         Complexity : O(N)
          */
        
        int n = nums.size();
        
        int i,j;
        for(i = n - 2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        
        // if largest dictionary order is given the i will be less then 0 
        if(i<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(j = n - 1 ; j >= i ; j--){
                if(nums[i] < nums[j]){
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
        
    }
};
