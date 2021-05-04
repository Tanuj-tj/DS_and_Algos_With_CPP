class Solution {
public:
    int maxProfit(vector<int> &arr) {
        int minSoFar = arr[0];
        int maxProfit = 0;
                     
        vector<int>::iterator itr;
        for(itr=arr.begin();itr!=arr.end();itr++){                    
           minSoFar = min(minSoFar,*itr);     
           int profit = *itr - minSoFar;     
           maxProfit = max(maxProfit,profit);   
        }
    return maxProfit;
    }
};
