class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // Using Recursion  41/62 test cases passed , rest time limit exceeds   
        
        if(m==1 || n==1) return 1;
        
        return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};
