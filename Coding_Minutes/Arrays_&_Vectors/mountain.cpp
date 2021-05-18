/*
Complexity : O(N+N)
*/

#include<bits/stdc++.h>
using namespace std;

//Complete this method, don't write main
int mountain(vector<int> &arr){

    int n=arr.size();
    int max_count = 0;
    // Skip the 1st and last element 
    for(int i=1;i<n-1;){

         // Search for peak
         if(arr[i]>arr[i+1] and arr[i]>arr[i-1]){
          
            int curr_count = 1;
            // Go Downword
            int j = i;
            while(j>=1 and arr[j]>arr[j-1]){
                j--;
                curr_count++;
            }
            // Go upwords
            while(i<=n-2 and arr[i]>arr[i+1]){
                i++;
                curr_count++;
            }
            max_count = max(max_count,curr_count);

         }
         else{
             i++;
         }
    }

    return max_count;
    
}

int main(){
    vector<int> arr = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<mountain(arr)<<endl;

    return 0;
}