#include<bits/stdc++.h>
using namespace std;

// Bruit Force : O(2^N)

// Optimized : Binary Search => O(NlogN)

bool isFeasible(vector<int> &arr, int m,int mid){

    int student = 1;
    int sum = 0;

    for(int i=0;i<arr.size();i++){  // 10 10 20 30
        if(sum + arr[i] > mid){  // F (0+10 > 50) // T (60 + 10 > 50) // F (10+10 > 50) // T(30+30 > 50)
            student++;    // 0+1 = 1+1=2
            sum = arr[i];  // 10 // 30
        }
        else{
            sum += arr[i];   // 50+10 = 60 // 10 + 20 = 30
        }
    }
    return student <= m;  // 2 <= 2 T 

}

int minPages(vector<int> &arr,int m){

    int min = *max_element(arr.begin(), arr.end());  // 30
    int max =  accumulate(arr.begin(), arr.end(), 0);  // 70 // 49
    int res = 0; // 50

    while(min <= max){
        int mid = (min + max) / 2; // 50 // 39
        if(isFeasible(arr,m,mid)){   // 50 // T
            res = mid;  // 50
            max = mid - 1;   // 49
        }
        else{
            min = mid + 1;
        }
    }

}

int main(){
    vector<int> arr = {10, 10, 20, 30};
    int m = 2;
    cout<<minPages(arr,m)<<endl;

    return 0;
}