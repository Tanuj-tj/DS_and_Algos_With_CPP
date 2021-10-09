#include <bits/stdc++.h>
#define lli long long int
using namespace std;
  
int majorityElements(int *arr,int n){
    
    // Step 1 : Find the Candidates
    int major = 0, count = 1;
    for(int i = 1 ; i < n ; i++){
        
        if(arr[major] == arr[i]) count++;
        else count--;
        
        if(count == 0){
            major = i;
            count = 1;
        }
    }

    // Step 2 : Check if majore is the majority element or not
    int count_major = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[major] == arr[i]) count_major++;
    }
    if(count_major  > n/2) return arr[major];
    else return -1;
}
  
int main()
{
    //write your code here
    int n; cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    cout<<majorityElements(arr,n)<<endl;

    return 0;
  }