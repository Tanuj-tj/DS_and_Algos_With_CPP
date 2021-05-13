#include <bits/stdc++.h>
using namespace std;

/*
Lower and Upper Bound Using Binary search 
-----------------------------------------

lower_bound returns an iterator pointing to the first element in the range [first,last] which has a value not less than ‘val’. 
upper_bound returns an iterator pointing to the first element in the range [first,last] which has a value greater than ‘val’. 
*/

// Lower Bound of a Element 
int lower_bound(vector<int> &v,int element){
    
    int low = 0, high = v.size()-1, mid;
    while(high-low > 1){
        mid = (low + high)/2;

        if(v[mid] < element){
            low = mid + 1;  
        } 
        else{
            high = mid;
        }
     }
     if(v[low] >= element){ 
        return low;
     }
     if(v[high] >= element){
          return high;   
      }
    return -1;
}

// Upper Bound of a Element 
int upper_bound(vector<int> &v, int element){
    
    int low = 0, high = v.size()-1, mid;
    while(high-low > 1){
        mid = (low + high)/2;

        if(v[mid] <= element){
            low = mid + 1;  
        } 
        else{
            high = mid;
        }
     }
     if(v[low] > element){ 
        return low;
     }
     if(v[high] > element){
          return high;   
      }
    return -1;
}

int main() {

    int n;cin >> n;
    vector<int> v(n); // n size
 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    int element; cin >> element;
    
    int lb = lower_bound(v,element); 
    cout << "Index of lower bound element : " << lb; 
    cout << " Lower Bound Element : " << (lb!=-1 ? v[lb] : -1) << endl;
    
    int ub = upper_bound(v,element); 
    cout << "Index of Upper bound element : " << ub; 
    cout << " Uppper Bound Element : " <<  (ub!=-1 ? v[ub] : -1) << endl;

    return 0;
}