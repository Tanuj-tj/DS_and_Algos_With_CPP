// Link : https://www.spoj.com/problems/AGGRCOW/

/*
Input :
* t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output :
For each test case output one integer: the largest minimum distance.

Example => 

Input:

1
5 3
1
2
8
4
9

Output:

3
*/

/*
Imp Points :

No. of stalls can be up to 10^5
Max distance between 2 stalls can be up to 10^9
No. of cows will always less then N
*/

#include<bits/stdc++.h>
using namespace std;


// Create Global 
const int N = 1e5+10;
int n,cows;
int positions[N];

// Create a predicate function which returns True or False
// The True which is at the maximum distance will be our result

bool canPlaceCows(int minDist){
    int lastPos = -1;
    int cows_ct = cows;
    for(int i = 0;i<n;i++){
        if(positions[i] - lastPos >= minDist || lastPos == -1){
            cows_ct--;
            lastPos = positions[i];
        }
        if(cows_ct == 0) break;
    }

    return cows_ct == 0;
}

int main(){
   
   // input test cases
   int t;
   cin>>t;

   while(t--){
       
       // input the no. of stalls and no. of cows
       cin>>n>>cows;
       
       // input the distance array
       for(int i=0;i<n;i++){
           cin>>positions[i];
       }

       // Sort the array before precessing further
       sort(positions,positions + n);   // NLog(N)

       // canPlaceCows will return TTTTTTTFFFFF.... something like that
       
       // min stall distance value can be 0
       // max stall distance value can be 10^9 

       int low = 0,high = 1e9;

       while(high - low > 1){

           int mid = ( low + high ) / 2;

           // if mid is true then ans is in right side
           if(canPlaceCows(mid)){
               low = mid;
           }
           else{
               high = mid - 1;
           }

        }   // log(10^9) * N

        if(canPlaceCows(high)){
            cout<<high<<endl;
        }
        else{
            cout<<low<<endl;
        }

        

   }
    return 0;
}