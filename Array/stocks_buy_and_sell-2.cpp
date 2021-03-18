#include<bits/stdc++.h>
using namespace std;

// a = [5,2,7,3,6,1,2,4]
    // 7 > 2
    // profit += 7 - 2  

int Approach(vector<int> &v){
    int profit = 0;
    for(int i=1;i<v.size();i++){
        if(v[i]>v[i-1]){
            profit+=(v[i]-v[i-1]);
        }
    }
    return profit;
}

int main(){
    vector<int> v = {5,2,7,3,6,1,2,4};
    cout<<Approach(v)<<endl;
    return 0;
}

