#include<bits/stdc++.h>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    int n = arr.size();
    vector<int> output(n,1);
    
    /* Approach 1 : O(N^2)
    // create a pair 
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        p[i].first = arr[i];
        p[i].second = i;
    } 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(p[i].second!=j){
                output[i]*=arr[j];
            }
        }
    }   */

    /* Approach 2 : O(N)
    // Multiply all the values of arr and divide it with every element

    int mul = 1;
    for(int i=0;i<n;i++){
        mul *= arr[i];
    }
    for(int i=0;i<n;i++){
        int check = mul / arr[i];
        output[i] *= check ;
    }
    */

   /*Approach 3 : O(N)
   // Keep 2 arrays left and right and keep the ith element fix and multiply left and right elements */
   
    vector<int> right(n+1);
    vector<int> left(n+1);

    right[0] = 1;
    left[n] = 1;
 
    // right   // 1 2 3 4  
    for(int i=1;i<=n;i++){
        right[i] = right[i-1] * arr[i-1];
    }

    // Left    // 3 2 1 0  
    for(int i=n-1;i>=0;i--){
        left[i] = left[i+1] * arr[i];
    }

    // Store the multiplication into output
    for(int i=0;i<n;i++){
        output[i] = right[i] * left[i+1];
    }
    
    return output;
}


int main(){
    vector<int> arr = {1,2,3,4};
    for(auto i:productArray(arr)){
        cout<<i<<" ";
    }
    return 0;
}