int maxLen(int A[], int n)
{
    map<int,int> mp;
    
    int max_i = 0;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        
        sum+=A[i];
        
        if(sum==0){ 
            max_i=i+1;
        }
        else{
            // Is our sum present in map
            if(mp.find(sum)!=mp.end()){
                max_i = max(max_i, i-mp[sum]);
            }
            // If not preset in map
            else{
                mp[sum] = i;
            }
        }
    }
    return max_i;
}
