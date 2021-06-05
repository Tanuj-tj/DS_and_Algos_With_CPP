/*
Sparse Search 
--------------

Given a sorted array of strings that is interspersed with empty strings, 
write a method to find the location of a given string.

Input :

["ai", "", "","bat", "","","car","gat","","","dog",""]
bat

Output :
4

*/

/*
Approach :

1. Use Linear Search : O(N)

2. We cannot use Binary search directly  : Worst case is again O(N) But Avg case is better then linera search
   * Use a modified version of binary search :
   - Here if mid is a empty string then we will linearly traverse in both 
     left and right direction to get a non empty string .
   - After getting a non empty string we can reduce the seatch space as the strings
     sorted so we now have to check either the left or to the right .
*/

#include<bits/stdc++.h>
using namespace std;

int sparse_search(string input[],int n,string key){
    // Use a modified binary search approach

    int s = 0;
    int e = n-1;

    while(s<=e){

        int mid = (s+e)/2;

        int left = mid-1;
        int right = mid+1;

        if(input[mid]==""){
            // Update our mid to point to a nearest non empty string
        
            while(1){
                if(left < s and right > e){
                    return -1;
                }
                else if(right <= e and input[right]!=""){
                    mid = right;
                    break;
                }
                else if(left >= s and input[left]!=""){
                    mid = left;
                    break;
                }
                left--;
                right++;
            }

        }
        if(input[mid]==key){
            return mid;
        } 
        else if(input[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return -1;
}

int main(){

    string input[] = {"ai", "", "","bat", "","","car","gat","","","dog",""};
    int n = 12;
    string key = "bat";

    cout<<sparse_search(input,n,key);
    
    return 0;

}

