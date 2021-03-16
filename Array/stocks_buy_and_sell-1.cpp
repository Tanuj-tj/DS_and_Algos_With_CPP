#include<iostream>
#include<algorithm>
using namespace std;

// Approach 1 - Naive approach , O(N^2)
template<class T>
T Approach_1(T arr[],int n){
    T max = 0;
    for(T i=0;i<=n;i++){
        for(T j=i+1;j<=n;j++){
            if(max<(arr[j]-arr[i]))
                max=(arr[j]-arr[i]);
        }
    }
    return max;
}

int Approach_2(int arr[],int n){
    int minSoFar = arr[0];
    int maxProfit = 0;
                                           // arr = [3,1,4,8,7,2,5]
    for(int i=0;i<n;i++){                    // Iterating through every element arr[0] = 3 , arr[1] = 1 , arr[2] = 4 , arr[3] = 8 , arr[4] = 7....
        minSoFar = min(minSoFar,arr[i]);     // minSoFar = min(3,3) => 3 , min(3,1) => 1 , min(1,4) => 1 , min(1,8) => 1 , min(1,7) => 1...
        int profit = arr[i] - minSoFar;      // profit = 3 - 3 = 0  , 1 - 1 = 0 , 4-1 = 3 , 8-1 = 7 , 7-1 = 6 .....
        maxProfit = max(maxProfit,profit);   // maxProfit = max(0,0) => 0 , max(0,0) => 0 , max(0,3) => 3 , max(3,7) => 7...........  
    }
    return maxProfit;
}
int main(){

    int arr[] = {3,1,4,8,7,2,5};
    int n=7;
    //cout<<Approach_1(arr,n)<<endl;
    cout<<Approach_2(arr,n)<<endl;
    return 0;
}