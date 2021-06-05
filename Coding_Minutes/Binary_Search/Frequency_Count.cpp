/*
Frequency Count
================

Given a sorted array which can contain repeaded elements and an element K,
we need to find the frequency of a given element.

Input Array :
[0,1,1,1,1,2,2,2,3,4,4,5,10] 
Key = 2

Output :
3
*/

/*
Approach :
1. Linear Search => O(N)
2. Binary Search => O(LogN)
    O/P = Last Occurance - First Occurance + 1 

    -> 2 Functions 
      - LowerBound()
      - UpperBound()

    -> or try some other varition with a check = True or False

3. Use Inbuilt upper_bound() and lower_bound() methods by C++ STL
*/

#include<bits/stdc++.h>
using namespace std;

int freq(vector<int> arr,int key,bool check){

    int s = 0;
    int e = arr.size()-1;
    int mid;
    int ans = -1;

    while(s<=e){
      
        mid = (s + e) /2 ;

        if(arr[mid]==key){
            ans = mid;
            // Go towards left or Right
            if(check){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            
        }
        else if(arr[mid]>key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;

}



int main(){

    vector<int> arr{0,1,1,1,1,2,2,2,3,4,4,5,10};
    int key = 2;
    bool check1 = true;
    bool check2 = false;
    int ans = freq(arr,key,check1) - freq(arr,key,check2) + 1;
    cout<<ans<<endl;;


    // Inbuilt STL Functions

    cout << upper_bound(arr.begin(),arr.end(),2) - lower_bound(arr.begin(),arr.end(),2)<<endl;

}


