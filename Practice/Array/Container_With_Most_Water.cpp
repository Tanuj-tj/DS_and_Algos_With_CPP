/*
Link : https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // 2 pointers
        
        int n = height.size();
        
        int i=0,j=n-1;
        
        int maxArea = INT_MIN;
        
        while(i<j){
            
            int length = min(height[i],height[j]);
            int breadth = j - i;
            int Area = length * breadth;
            
            maxArea = max(maxArea,Area);
            
            if(height[i]<height[j]) i++;
            else j--;
        }
        
        return maxArea;
    }
};
