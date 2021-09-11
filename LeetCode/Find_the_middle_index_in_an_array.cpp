#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Optimized Appraoch : O(N), O(1)
    int findMiddleIndex(vector<int>& nums){
        
        int n = nums.size();

        if(n==1) return 0;

        int sum = 0;

        for(int i = 0 ; i < n ; i++) sum+=nums[i];

        int temp = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            temp+=nums[i];

            int lsum = temp - nums[i];
            int rsum = sum - nums[i];
            
            if(lsum==rsum) return i;
        }

        return -1;   
    }

    // Bruit Force Appraoch : O(N^2)
    /*
    int vectorSum(vector<int> v,int lower_lim,int upper_lim){
        int sum = 0;
        for(int i = lower_lim; i <= upper_lim; i++) sum+=v[i];
        return sum;}
    
    int findMiddleIndex(vector<int>& nums) {
         
        int n = nums.size();       // nums = [2,3,-1,8,4] n = 5 
        if(n==1) return 0;
        
        int pivot = 0;  
        
        vector<int> temp(n+2,0);             
        for(int i = 1 ; i <= n ; i++){
            temp[i]+=nums[i-1];           // nums = [0,2,3,-1,8,4,0]
        }
        // for(auto i : temp){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        while(pivot+1 <= n){
            int x = vectorSum(temp,0,pivot);
            int y = vectorSum(temp,pivot+2,n+2);
            cout<<x<<" "<<y<<endl;
            if(x==y){
                return pivot;
            }
            pivot++;
        }
        
        return -1;}
    */
};

int main(){

    Solution obj;
    vector<int> nums{2,3,-1,8,4};
    cout<<obj.findMiddleIndex(nums)<<endl;
    return 0;
}
