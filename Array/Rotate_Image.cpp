class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // O(N^2)
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // O(N)
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end()); // O(N)
        }
        
        //=> total complexity = O(n^2) + O(N) * O(N) = O(N^2)
    }
};
