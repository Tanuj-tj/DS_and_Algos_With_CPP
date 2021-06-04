/*
Inversion Count
---------------

Given an array containing integers, you need to count the total number of inversions.

Inversion :- Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i <j.

Sample Input :

[0, 5, 2, 3, 1]

Sample Output :

5
*/

#include <bits/stdc++.h>
using namespace std;

// Merge
// Helper Function
int merge(vector<int> &arr,int s,int e){  // s = 0, e = 1
    int i=s;  // 0
    int mid = (s+e)/2;  // 0
    int j=mid+1;  // 1

    vector<int> temp;  //[5,10]

    int count = 0;
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
           
            count += (mid - i + 1);
            temp.push_back(arr[j]);   // 5
            j++;
        }
    }  

    // If elements still remains in any part of array
    while(i<=mid){
        temp.push_back(arr[i++]);  // 10
    }
    while(j<=e){
        temp.push_back(arr[j++]);
    }

    int k=0;
    for(int idx=s;idx<=e;idx++){
        arr[idx] = temp[k++];
    }
    // 0  1
    // 5 10
    return count;

}

// Merge Sort
int inversion_count(vector<int> &arr,int s,int e){
    // Base case
    if(s>=e){
        return 0;
    } 
    // Divide 
    int mid = ( s + e ) / 2;
    int c1 = inversion_count(arr,s,mid);    // 2
    int c2 = inversion_count(arr,mid+1,e);   // 0
    int cI =  merge(arr,s,e); 
    return c1 + c2 + cI; 

}

int main(){

    vector<int> arr{2,4,3,5,1};
    
    int s = 0;
    int e = arr.size()-1;

    cout<<inversion_count(arr,s,e)<<endl;

    return 0;
}
