/*
Staircase Search

You are given a M x N matrix which is row wise and column wise sorted. You have to search the
index of a given integer K in the matrix.

Input Format:

Function contains integer M, integer N ,2D vector containing integers and an integer k.

Output Format:
Return a pair of integers {x,y} where x is the row index and y is column index of k in the matrix.

Expected Complexity:

Linear O(N)

Sample Testcase:

Input :
33

1 4 9
2 5 10
6 7 11

10

Output:
{1,2}

Explanation:

Index of 10 in matrix is 1,2.
*/

#include<bits/stdc++.h>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    
    // Start from (0,N-1)
    // If Key > (0,N-1) then go to (1,N-1)
    // If key < (0,N-1) then go to (0,N-2)
    
    int i = 0;      // (i,j)
    int j = n-1;
    while(j>=0 and i<m){
        if(k == v[i][j]){
            return {i,j};
        }
        if(k > v[i][j]){
            i++;
        }
        else{
            j--;
        }

    }
    return {-1,-1};
    
}

int main(){
    int m=3;
    int n=3;
    vector<vector<int>> v{ {1,4,9},{2,5,10},{6,7,11} };
    int k = 10;
    
    auto ans = search(m,n,v,k);
    cout<<ans.first<<" "<<ans.second;

    return 0;
}