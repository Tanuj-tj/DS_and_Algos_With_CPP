#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    // will return an address (pointer) in case of array
    // in case of vector it will return an iterator
    int min = *min_element(v.begin(),v.end());     // O(n)
    cout<<min<<endl;
    
    int max = *max_element(v.begin(),v.end());      // O(n)
    cout<<max<<endl;
    
    // sum of elements
    int sum = accumulate(v.begin(),v.end(),0);       // O(n)
    cout<<sum<<endl;
    
    // count of a perticula element // eg. 3
    int ct = count(v.begin(),v.end(),3);              // O(n)
    cout<<ct<<endl;
    
    // find an element
    auto it = find(v.begin(),v.end(),2);               // O(n)
    if(it!=v.end())
        cout<<*it<<endl;
    else
        cout<<"Element not found";
        
    // Reverse a string or a vector
    reverse(v.begin(),v.end());                        // O(n)
    for(auto val:v){
        cout<<val<<" ";
    }
    cout<<endl;
    
    string s = "abcdefghijk;
    reverse(s.begin(),s.end());                        // O(n)
    cout<<s<<endl;
     
     
    //---Array------//
    
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int min = *min_element(n,arr+n);     // O(n)
    cout<<min<<endl;
    
    
    return 0;
}
