/*
Rotated Search
==============

Write a function that takes input an sorted array of
distinct integers, which is rotated about a pivot point and
finds the index of any given element.

Sample Input :
[4,5,6,7,0,1,2,3]
k =6

Sample Output :
2
*/

/*
Steps :
1. Find the mid
2. Chek if the left part is sorted or not 
   -> arr[0] < arr[mid] 
   if sorted then check if the element is present or not 
   -> arr[0] < = key < = arr[mid]
   if present then appy binary search  
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vii vector<int,int>
#define vi vector<int>
#define F first
#define S second


int rotated_search(vi arr,int key){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid;

    while(s<=e){
       
       mid = ( s + e ) /2;

       // Check for sorted
       if(arr[mid]==key){
           return mid;
       }

       if(arr[s] <= arr[mid]){
           if(arr[s] <= key and key < arr[mid]){
               e = mid-1;
           }
           else{
               s = mid + 1;
           }
       }
       else{
           if(arr[mid] > key  and key >= arr[e]){
               s = mid+1;
           }
           else{
               e = mid - 1;
           }

       }
    }
    return -1;
}

int main(){
    vi arr = {4,5,6,7,0,1,2,3};
    int key = 0;
    cout<<rotated_search(arr,key);
    return 0;
}