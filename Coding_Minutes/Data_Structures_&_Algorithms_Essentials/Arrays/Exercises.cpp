#include <bits/stdc++.h>
using namespace std;


int MaxSum(vector<int> arr){
    int maxSum = 0;
    int currSum = 0;
    
    for(int i = 0 ; i < arr.size() ; i++){
        cout<<"Current Sum "<<currSum<<endl;
        currSum = max(currSum + arr[i], arr[i]);
        cout<<"Max Sum "<<maxSum<<endl;
        maxSum = max(currSum,maxSum);
    }}

int lowerBound(vector<int> A, int Val) {
    // Lower bound means :
    //Either that value itself or a value just less then that
    
    // Search
    for(auto x:A){
        if(Val == x) return Val;
    }
    
    for(auto x:A){
        if(Val-1 == x) return x;
    }
    
    return 0;}

pair<int, int> closestSum(vector<int> arr, int x){
    // your code goes here
    
    int n = arr.size();
    int finalSub = INT_MAX;
    int a,b;

    for(int  i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int currSum = arr[i] + arr[j];
            int currSub = abs(x - currSum);
            if(currSub <= finalSub){
                a = arr[i];
                b = arr[j];
                finalSub = currSub;
            }
        }
    }

    return {a,b};}

vector<int> kRotate(vector<int> a, int k){
    // your code  goes here
    
    int n = a.size();

    vector<int> ans(a);

    // Edge case
    if(k == n) return ans;

    for(int i = 0 ; i < k ; i++){
        
        int s = 0;
        int e = n - 1;

        while(s < e){
            swap(ans[s++],ans[e]);
        }
    }
    return ans;}



int main()
{
    //vector<int> arr{1,-2,3,4,4,-2};
    //cout<<MaxSum(arr);
    //vector<int> A{-1,-1,2,3,5};
    //int Val = 4;
    //vector<int> A1{1,2,3,4,6};
    //int Val1 = 4;
    //cout<<lowerBound(A1,Val1);

    // vector<int> arr{10,22,28,29,30,40};
    // int x = 54;
    // auto ans = closestSum(arr,x);
    // cout<<ans.first<<" "<<ans.second<<endl;

    // vector<int> arr{1,3,5,7,9};
    // int x = 2;
    // auto ans = kRotate(arr,x);
    // for(auto i : ans){
    //     cout<<i<<" ";
    // }


    return 0;
}
