/*
Given an array of size N, find the minimum number of swaps needed to make the array as sorted.

Sample Input :
a1 = [5,4,3,2,1]

Sample Output : 
2 
*/

#include<bits/stdc++.h>
using namespace std;

int countMinSwaps(vector<int> &arr){

    int n = arr.size(); 

    // Keep track of indices of current array
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        p[i].first = arr[i];
        p[i].second = i;
    }
    // Sort the pair 
    sort(p,p+n); 

    // Keep Track of visited elements
    vector<int> visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++){

        // If the element is at its right postion or it is already visited
        int old_position = p[i].second;
        if(visited[i]==true or old_position == i){
            continue;
        }

        // Visiting the element for the first time
        int node = i;
        int cycle = 0;

        while(visited[node]==false){
            visited[node] = true;
            int next_node = p[node].second;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle-1);
    }
    return ans;    

}

int main(){
    vector<int> arr = {5,4,3,2,1};
    cout<<countMinSwaps(arr)<<endl;
    return 0;
}
