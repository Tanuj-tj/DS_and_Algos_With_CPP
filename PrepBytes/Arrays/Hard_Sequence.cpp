#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int printArray(int *arr,int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int countSequence(int n){
    
    int visited[n+1] = {0};
    int arr[n+1];
    arr[0] = -1;
    arr[1] = 0;
    
    for(int i = 2 ; i <= n ; i++){
        int x = arr[i-1];
        if(visited[arr[i-1]] != 0){
            arr[i] = (i-1) - visited[arr[i-1]];
        }
        else{
            arr[i] = 0;
        }
        visited[arr[i-1]] = i-1;
    }

    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        if(arr[i] == arr[n]) count++;
    }

    return count;
}

int main()
{   
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<countSequence(n)<<endl;
    }
    
    return 0;
}