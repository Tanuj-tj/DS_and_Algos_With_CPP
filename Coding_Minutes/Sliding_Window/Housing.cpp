/*
Along one side of a road there is a sequence of vacant
plots of land. Each plot has a different area (non-zero). So,
the areas form a sequence A[i], A[2], A[N].

You want to buy K acres of land to build a house. You want
to find all segments of continguous plots (i.e. a subsection
in the sequence) of whose sum is exactly K.

Sample input :

Plots = [1 3 2 1 4 1 3 2 1 1 2]
K=8 

Sample Output :

2 5
4 6 
5 9

*/

/* Approach  */

// Bruit Force Approach may take : O(N^3) => N*N loops + N for the sum
// Optimized approach may take a prefix sum so it will become  : O(NLogN)
// Best Approach will be achieved through sliding window : O(N)  

#include<bits/stdc++.h>
using namespace std;

class Housing{
    public:

    // All the windows that has the sum = k   
    void housing(int *arr,int n,int k){
        
        // Maintain a window which has the sum = k

        int i = 0;
        int j = 0;
        int curr_sum = 0;

        while(j<n){
            
            // expand to right
            curr_sum +=arr[j];
            j++;

            // remove elements from the left till curr_sum > k
            while(curr_sum > k and i<j){
                curr_sum -= arr[i];
                i++;
            }
    
            if(curr_sum == k){
                cout<<i<<" - "<<j<<endl;
            }


        } 
    }
    // All smallest windows that has the sum = k   
    void housing_smallest(int *arr,int n,int k){
        
        // Maintain a window which has the sum = k

        int i = 0;
        int j = 0;
        int curr_sum = 0;
        int small = INT_MAX; 
        int a,b;

        while(j<n){
            
            // expand to right
            curr_sum +=arr[j];
            j++;

            // remove elements from the left till curr_sum > k
            while(curr_sum > k and i<j){
                curr_sum -= arr[i];
                i++;
            }

               
            if(curr_sum == k){
                int curr_small = j - i;
                if(curr_small < small){
                    small = curr_small;
                    a = i;
                    b = j;
                }
            }

        } 
         cout<<a<<" - "<<b<<endl;
    }

};

int main(){
    
    int plots[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;

    Housing *obj = new Housing();
    obj->housing(plots,n,k);
    obj->housing_smallest(plots,n,k);
    return 0;
}