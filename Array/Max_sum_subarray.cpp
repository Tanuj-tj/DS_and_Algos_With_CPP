/*This can be performed using 2 approaches 
Approach 1: Brute Force -> O(N^3)
Approach 2: Cummulative sum technique -> O(N^2) 
Approach 3: Kadane’s Algorithm: -> O(N)
*/

#include<bits/stdc++.h>
using namespace std;

int Approach_1(int arr[],int n){

    int max_sum = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;
}

int Approach_2(int arr[] ,int n){
    int currsum[n+1];
    currsum[0] = 0;

    for(int i=1;i<=n;i++){
        currsum[i] = currsum[i-1] + arr[i-1];
    }

    int max_sum = INT_MIN;
    for(int i=1;i<=n;i++){
        int sum = 0;
        max_sum = max(max_sum,currsum[i]);
        for(int j=1;j<i;j++){
            sum = currsum[i] - currsum[j-1];
            max_sum = max(sum,max_sum);
        }

    }
    return max_sum;
}

int Approach_3(int arr[],int n){
    int max_sum = 0;
    int curr_sum = 0;

    for(int i=0;i<n;i++){
        curr_sum = curr_sum + arr[i];
        if(curr_sum > max_sum){
            max_sum = curr_sum;
        }
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    return max_sum;
}

int main(){
    
    int arr_1[] = {-2,-3,4,-1,-2,1,5,-3};
    int arr_2[] = {-2,-3,4,-1,-2,1,5,-3};
    int arr_3[] = {-2,-3,4,-1,-2,1,5,-3};
    cout<<"Approach_1: "<<Approach_1(arr_1,8)<<endl;
    cout<<"Approach_2: "<<Approach_2(arr_1,8)<<endl;
    cout<<"Approach_3: "<<Approach_3(arr_2,8)<<endl;

    return 0;
}