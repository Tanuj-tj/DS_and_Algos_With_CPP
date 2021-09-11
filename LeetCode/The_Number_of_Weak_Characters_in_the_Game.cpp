class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    } 
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        int n = properties.size();
        
        sort(properties.begin(),properties.end(),comp);
        reverse(properties.begin(),properties.end());
        
        int mx=INT_MIN;
        int ans = 0;
        for(auto i : properties){
            if(i[1]<mx) ans++ ;
            mx=max(mx,i[1]);
        }
        
        return ans;
        
    }
};
