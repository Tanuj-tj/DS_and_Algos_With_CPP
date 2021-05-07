class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Resultant vector
        vector<vector<int>> ans;
        
        if(intervals.size()==0) return ans;
        
        // Sort the given intervals
        sort(intervals.begin(),intervals.end());
        
        // intervals = [ [1,3] , [2,6] , [8,10] , [15,18] ]
        // check = [1,3]
        vector<int> check = intervals[0];   // [1,4]
        
        for(auto i:intervals){           // i=  [1,4]
            if(i[0] <= check[1]){       // 1 < 4 F
                check[1] = max(i[1], check[1]);
            }
            else{
                ans.push_back(check);    // ans => 
                check = i;
            }
        }
        
        ans.push_back(check);
        return ans;
        
        
    }
};
