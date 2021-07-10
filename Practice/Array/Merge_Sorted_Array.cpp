/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Eg. 

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

*/
/*
Approach :
Start from the last element of both the arrays and check for the greater element via 2 poiners (x,y in my case) then insert the 
greater element into the m+n th index of nums1 array then keep doing the same
Later if the nums2 array is left with some elements then via while loop insert the remaining elements into nums1 array .

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int currPos = n+m-1;  // Last pos of num1
        
        int x=m-1,y=n-1;
        
        while(x>=0 and y>=0){
            
            if(nums1[x] >= nums2[y]){
                nums1[currPos] = nums1[x--];
                
            }
            else{
                nums1[currPos] = nums2[y--];
            }
            currPos--;
        }
        
        while(y>=0){
            nums1[currPos--] = nums2[y--];
        }
    }
};
