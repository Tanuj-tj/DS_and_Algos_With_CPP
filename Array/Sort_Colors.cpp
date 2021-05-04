// Dutch national Flag algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [2,0,2,1,1,0] => [0,0,1,1,2,2]
        
        //sort(nums.begin(),nums.end()); //
        
        int low = 0, mid = 0, high = nums.size()-1;  // 0<=low , high=>2
        
        while(mid<=high){
            
            switch(nums[mid]){ // 0 , 1, 2
                
                case 0:
                    swap(nums[low++],nums[mid++]);
                    break;
                
                case 1:
                    mid++;
                    break;
            
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
     }
};
