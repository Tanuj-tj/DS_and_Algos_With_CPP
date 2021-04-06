/*
Heap Sort Steps:
1. CreateHeap of 'n' elements
2. Delete 'n' elements 1 by 1
*/

#include<bits/stdc++.h>
using namespace std;

// Inserting an element inside heap
void Insert(int H[],int n){
    int temp, i = n;
    temp = H[i];

    while(i > 1 && temp > H[i/2]){
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}

// Deleting elemets from a heap
int Delete(int H[],int n){

    int i,j,x,val;
    val=H[1];
    x = H[n];
    H[1] = H[n];
    H[n] = val;  // Deleted Elements strored in a free space available at the end of the array
    i=1;j=i*2;

    while(j<n-1){
        if(H[j+1] > H[j])
            j = j+1;

        if(H[i] < H[j]){

            // Perform Swaping
            int temp = H[i];
            H[i] = H[j];
            H[j] = temp;

            i = j;
            j = 2*j;
        }
        else
            break;
    }
    return val;
}

int main(){

    // Creating a heap
    int H[] = {0,10,20,20,25,5,40,35};
    //Result should be {40,25,35,10,5,20,30} 

    int i;
    for(i=2;i<=7;i++){
        Insert(H,i);
    }

    cout<<"Heap : ";
    for(i=1;i<=7;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
    
    for(i=7;i>1;i--){
        cout<<"Deleted Value is : "<<Delete(H,i)<<endl;
    }
    
    cout<<"Heap After Deletion : ";
    for(i=1;i<=7;i++)
        cout<<H[i]<<" ";
    
    return 0;
}