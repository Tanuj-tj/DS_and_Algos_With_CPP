#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> &arr,int key){
    int start = 0;
    int end = arr.size()-1;
    int mid;

    while(start<=end){

        mid = ( start + end ) / 2;

        if(arr[mid] == key) return true;

        if(arr[start] < arr[mid]){
            if( (arr[start] <= key) and (arr[mid] > key) ){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            if( (arr[end] >= key) and (arr[mid] < key) ){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }

        }
    }
    return false;
}

int main(){
    vector<int> arr = {120,130,40,50,90,100,110};
    int key = 220;
    bool ans = find(arr,key);
    if(ans) cout<<"Element Found";
    else cout<<"Not Found";
    return 0;
}
