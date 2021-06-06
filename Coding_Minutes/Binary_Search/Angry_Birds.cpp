/*
Angry Birds
===========

There is a long wire along at straight line, which contains
N bird nests at positions x1, x2 ....xN.

There are B(B<=N) birds, which become angry towards
each other once put into a nest. To put the birds from
hurting each other you want to assign birds to nests such
that minimum distance between any two birds is as large
as possible. What is the largest minimum distance? 

Input :

N = 5 Nests
B = 3 Birds
Nests = [1,2,4,8,9]

Output :

3

Approach :
1. Bruite Force 
   -> Check all possibile places for the birsd to sit
      - N 
         C
          B

2. Use binary search 
  -> mid will be the mininmum distance that the birds can be placed
  -> then try to maximize the min distance .      
  -> Complexity : O( N+Log(Largest Distance b/w coordinates) )    
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vi vector<int>
#define F first
#define S second
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;

bool canPlaceBirds(int B,int N,vi nests,int mid){
    
    int birds = 1;
    int location = nests[0];

    for(int i=1;i<=N-1;i++){
        int curr_location = nests[i];
        if(curr_location - location >= mid){
            birds++;
            location = curr_location;

            if(B==birds){
                return true;
            }
        }
    }

    return false;
}

int main(){
  
    int B = 3; // No. of birds
    vi nests{1,2,4,8,9};
    int N = nests.size();  // No. of Locations of nests
    
    // Sort the nest loc. in case not alreasy sorted
    sort(nests.begin(),nests.end());  // Worst Case : O(NlogN)

    // Binary Search 

    int s = 0;
    int e = nests[N-1] - nests[0]; // 
    int ans = -1;

    while(s<=e){
        int mid = (s+e)/2;

        bool canPlace = canPlaceBirds(B,N,nests,mid);  // {TTTTTTTTFFFFFFF......}

        if(canPlace){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    cout<<ans<<endl;

	return 0;
}