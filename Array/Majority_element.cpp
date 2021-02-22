#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach :
void Approach_1(int arr[],int n){
    int maxcount = 0;
    int count = 0;
    int index = -1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count>maxcount){
            maxcount = count;
            index = i;
        }

    }
    if(maxcount> n/2){
        cout<<arr[index]<<endl;      
    }
    else{
        cout<<"Majority Element does not exist"<<endl;
    }
}

// Moor's voting Algorithm
int Approach_2(int *arr,int n){
    
    // Sort the array
    sort(arr,arr+n); // O(nlogn)

    int count=1;
    int max_element = -1;
    int temp = arr[0];
    int element;
    int f = 0;

    for(int i=1;i<n;i++){
        if(temp==arr[i]){
            count++;
        }
        else{
            count = 1;
            temp = arr[i];
        }

        if(max_element<count){
            max_element = count;
            element = arr[i];

            if(max_element>(n/2)){
                f=1;
                break;
            }
        }
    }

    return (f==1 ? element : -1);
}

int main(){
 
    int n1=6;
    int arr1[] = {3, 3, 4, 2, 4, 2};
   
    cout<<"Approach 1"<<endl;
    Approach_1(arr1,n1);

    int arr2[] = {1, 1, 2, 1, 3, 5, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout<<"Approach 2"<<endl;
    cout<<Approach_2(arr2,n2);


    return 0;
}