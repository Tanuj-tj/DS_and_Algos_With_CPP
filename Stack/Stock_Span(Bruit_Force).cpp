#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {100,80,60,70,60,75,85}; 
    int temp[arr.size()];
    
    int count = 0;
    
    for(int i=arr.size()-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            if(arr[i]>=arr[j]){
                count++;
                temp[i] = count;   
            }
            else if(arr[i]<arr[j]){
                count = 0;
                break;
            }
        }
    }
    
    for(int i=0;i<arr.size();i++){
        cout<<temp[i]<<" ";
    }
    
    return 0;
}
