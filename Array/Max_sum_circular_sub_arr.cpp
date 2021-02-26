#include<bits/stdc++.h>
using namespace std;

int kedane(int arr[],int n){
    int max_sum = INT_MIN;
    int curr_sum = 0;

    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        if(curr_sum<0){
            curr_sum = 0;
        }
        max_sum = max(max_sum,curr_sum);
        
    }
    return max_sum;
}

int main(){
    int n = 7;
    int arr[] = {4,-4,6,-6,10,-11,12};
    int wrap_sum;
    int nonwrap_sum;

    nonwrap_sum = kedane(arr,n);
    // cout<<nonwrap_sum<<endl; => 12
    int total_sum = 0;
    for(int i=0;i<n;i++){
        total_sum+=arr[i];  // 4 + (-4) + 6 + (-6) + 10 + (-11) + 12 => 13
        arr[i] = -arr[i];   // {-4, 4, -6, 6, -10, 11, -12}
    }
     
    // cout<<kedane(arr,n)<<endl; => 11
    wrap_sum = total_sum + kedane(arr,n);

    cout<<max(wrap_sum,nonwrap_sum)<<endl;
    return 0;
}