#include<bits/stdc++.h>
#include<algorithm>
using namespace std;                      
                                          // Index => 0 1 2 3 4 5 6 7
int Rain_water_trapping(int a[],int n){    // a =>   {3,1,2,4,0,1,3,2}
    int left[n];                           // left =>{3,3,3,4,4,4,4,4} 
    int right[n];                          //        {4,4,4,4,3,3,3,2}  <= right             

    left[0] = a[0];                        // left[0] = 3 
    for(int i=1;i<n;i++){                  // i = 1 , left[1] = max(3,1) => 3 || i = 2 , left[2] = max(3,2) => 3 || i = 3, left[3] = max(3,4) => 4 || i = 4 , left[4] = max(4,0) => 4 
        left[i] = max(left[i-1],a[i]);
    }

    right[n-1] = a[n-1];                   //  right[7] = a[7] , right[7] = 2
    for(int i=n-2;i>=0;i--){               // i = 6 , right[6] = max(2,3) => 3 || i = 5 , right[5] = max(3,1) => 3 || i = 4 , right[4] = max(3,0) => 3...........
        right[i] = max(right[i+1],a[i]);
    }

    int ans = 0;                            // ans = 0 + 0 + 2 + 1 + 0 +  3 + 2 +  0 + 0 => 7
    for(int i=0;i<n;i++){                   // i = 7 , ans = min(4,2) - 2 , ans = 2 - 2 => 0
        ans+=(min(left[i],right[i])-a[i]);
    }
    return ans;
    

}

int main(){
    int n = 8;
    int v[8] = {3,1,2,4,0,1,3,2};

    cout<<Rain_water_trapping(v,n)<<endl;

    return 0;
}