class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans(numRows); // n = 2 [[],[]]
        for(int i=0;i<numRows;i++){              // [[1],[1,1]]
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            
            // if numRows >= 2
            for(int j=1;j<i;j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];    // [0][0] + [0][1]
                    
            }
        }
        
        return ans;
    }
};
