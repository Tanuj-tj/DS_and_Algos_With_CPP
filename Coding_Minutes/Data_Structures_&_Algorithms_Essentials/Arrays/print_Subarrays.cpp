// Printing Subarrays

#include <bits/stdc++.h>

using namespace std;

// O(N^3)
void printSubarrays(int arr[], int n){
    
    vector<int> sumArr;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            int sum = 0;
            for(int k = i ; k <= j ; k++){
                sum+=arr[k];
                cout<<arr[k]<<",";
            }
            sumArr.insert(sum);
            cout<<" | Sum : "<<sum;
            cout<<endl;
        }
    }
    
    cout<<"Max Sum : "<<*max_element(sumArr.begin(), sumArr.end());
}

int main()
{
    int arr[] = {-2,3,4,5,4,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    printSubarrays(arr,n);

    return 0;
}
