class Solution {
public:
    
    vector<vector<int>> ans;
    
    void generate(vector<int> &nums,int i, vector<int> &current){
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }
        generate(nums,i+1,current);
        current.push_back(nums[i]);
        generate(nums,i+1,current);
        current.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> current;  // Empty vector
            generate(nums,0,current);
            return ans;
        
    }
};
