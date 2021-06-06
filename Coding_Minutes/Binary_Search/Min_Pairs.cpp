/*
Min Pair
========

Given two non-empty arrays, find the pair of numbers
(one from Ieach array) whose absolute difference is
minimum. Print the any one pair with the smallest
difference.

Sample Input

a1 = [-1, 5, 10, 20, 3]

a2 = [26, 134, 135, 15, 17]


Sample Output :
[20, 17]


Approach :
1. Bruite Force => Find the sum of all the possibel pairs
   -> O(N*M)

2. Modified Binary Search
   -> O(MLogM + NLogM)
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

void min_pair(vi a1,vi a2) {
    // Sort a2 
    // Lineraly iterate through a1 and check its lowerBound in a2
    // min_p = min(a1[i] - lowerBound(a2  ,a1[i]) )

    sort(a2.begin(),a2.end());

    int p1,p2;

    int diff = INT_MAX;

    for(int i : a1){
        auto lb = lower_bound(a2.begin(),a2.end(),i) - a2.begin();  // lb will contain a index of lower bound of i in a2
        
        // Left
        if(lb >= 1 and i - a2[lb-1] < diff){
            diff = i - a2[lb-1];
            p2 = i;
            p1 = a2[lb-1];
        }

        // Greater/ Right
        if(lb!=a2.size() and a2[lb]-i < diff){
            diff = a2[lb] - i;
            p1 = i;
            p2 = a2[lb];
        }
    }

    cout<<" Min Pair " <<p1<<" and "<<p2<<endl;
     
}

int main(){
  
    vi a1{-1, 5, 10, 20, 3};
    vi a2{26, 134, 135, 15, 17};
    min_pair(a1,a2);
	return 0;
}