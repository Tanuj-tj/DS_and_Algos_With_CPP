#include<bits/stdc++.h>
using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    
    int min_val = INT_MAX;
    pair<int,int> p;
    // O(N^2)
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            int check = abs(a[i]-b[j]); 
            if(check < min_val){
                min_val = check;
                p.first = a[i];
                p.second = b[j];
            }
        }
    }
    
    return p;
    
}
