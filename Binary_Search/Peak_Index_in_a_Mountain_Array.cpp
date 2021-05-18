class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        
        // Bruit force is to find the index of max element : O(N)
        
        // Use Binary Serch to optimize it : O(LogN)
        
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            
            int mid = ( end + start ) / 2;
            
            if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1] and arr[mid]<arr[mid-1]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        
        return -1;
        
    }
};
