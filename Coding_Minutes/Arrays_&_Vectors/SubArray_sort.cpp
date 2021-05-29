#include <bits/stdc++.h>
using namespace std;

// Apprpach 1 :
// Steps 
// 1. Create a copy of array
// 2. Sort the original array
// 3. Compare both the array from i->n and j->0
// 4. Return (i,j) or (-1,1)
// Complexity : Time =>  O(N+N) and Space => O(N)

vector<int> SubArray_sort_A1(vector<int> &arr){

    // Size of array
    int n = arr.size();

    // Create a copy of given array
    vector<int> temp(arr);

    // Sort the given array
    sort(arr.begin(),arr.end());

    // Traverse and match the elements with sorted array 
    int i=0;
    while(i<n and arr[i]==temp[i]){
        i++;
    }
    int j=n-1;
    while(j>=0 and arr[j]==temp[j]){
        j--;
    }

    if(i==n || j==0) return {-1,-1};
    return {i,j};
}

// Approach 2 : O(N)
// 1. Traverse and check => if a[i] > a[i-1] or a[i] < a[i+1]
// 2. Keep Track of smaller and larger elements while traversal
// 3. Find the appropriate pace for them and retrun the index of those palces


// Helper Function to out of order element
bool OutOfOrder(vector<int> &arr, int i){
    
    if(i==0){
        return arr[i] > arr[i+1];
    }
    else if(i ==arr.size()-1){
        return  arr[i] < arr[i-1];
    }
    return arr[i] > arr[i+1] or arr[i] < arr[i-1];
}

pair<int,int> SubArray_sort_A2(vector<int> &arr){

    // Size of array
    int n = arr.size();

    int smaller = INT_MAX;
    int larger = INT_MIN;

    for(int i=0;i<n;i++){
        
        if(OutOfOrder(arr,i)){
            smaller = min(smaller,arr[i]);
            larger = max(larger,arr[i]);
        }
    }
   
    // If array is sorted
    if(smaller==INT_MIN) return {-1,-1}; 

    int left = 0;
    while(smaller >= arr[left]) left++;
    
    int right = arr.size()-1;
    while(larger <= arr[right]) right --;
    
    return {left,right};

}


int main(){

    vector<int> arr = {1,2,3,10,4,2,3,5};
    for(auto i:SubArray_sort_A1(arr)){
        cout<<i<<" ";
    }cout<<endl;

    auto p = SubArray_sort_A2(arr);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}