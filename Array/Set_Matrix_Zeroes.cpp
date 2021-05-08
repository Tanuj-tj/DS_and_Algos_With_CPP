class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        //       0 1 2 3
        // Eg. [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
        //          0          1        2
        int col0 = 1; 
        int row = matrix.size();  // 3 => 0,1,2
        int col = matrix[0].size(); // 4  => 0,1,2,3

        for(int i=0;i<row;i++){
            if(matrix[i][0] == 0) col0 = 0;
            
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0) 
                    matrix[i][0] = matrix[0][j] = 0;
            }
            
        }
        
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) 
                    matrix[i][j]=0;        
            }
            if(col0==0) matrix[i][0]=0;
            
        }
        
        
        
    }
};
