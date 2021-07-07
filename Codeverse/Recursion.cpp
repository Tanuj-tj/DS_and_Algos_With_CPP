#include <bits/stdc++.h>

using namespace std;


// Check for a Palindromic String : O(n/2)
bool checkPalindrom(string s,int n,int i){
    
    if(i >= s.size()) return true;
    
    if(s[i] == s[n-1-i]){
        return checkPalindrom(s,n,i+1);
    }
}

// Subsequences / Subset 
void Subsequences(vector<int> &arr,int i,vector<int> &ans){
    
    // At every index we have two choices
    if(i == arr.size()){
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
        
        return;
    }
    
    ans.push_back(arr[i]);
    
    // Pick the ith index
    Subsequences(arr,i+1,ans);
    
    ans.pop_back();
    
    // Do Not pick the ith index
    Subsequences(arr,i+1,ans);
    
}


int main()
{
    string s = "madam";
    cout<<checkPalindrom(s,s.size(),0)<<endl;
    
    string s1 = "mad";
    cout<<checkPalindrom(s1,s1.size(),0)<<endl;
    
    vector<int> arr{1,2,3};
    vector<int> ans;
    
    Subsequences(arr,0,ans);
    

    return 0;
}
