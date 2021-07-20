/*
Link : https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // Solution : Transpose + Reverse
        
        // Transpose : [[1,4,7],[2,5,8],[3,6,9]]
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // Reverse Every Row
        for(int i = 0 ; i < matrix.size() ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
