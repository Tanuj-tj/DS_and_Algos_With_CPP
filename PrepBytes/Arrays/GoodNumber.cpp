#include <bits/stdc++.h>
#define lli long long int
using namespace std;
  
  
lli power(lli x, lli y)
{
  
    // If x^0 return 1
    if (y == 0)
        return 1;
  
    // If we need to find of 0^y
    if (x == 0)
        return 0;
  
    // For all other cases
    return x * power(x, y - 1);
}
  
  
lli goodnumber(lli n){
   
   if(n==1) return 1;
   
   lli sum =0, k=0 , pow3 = 0;
       vector<lli> pow3_vi;
       
       while(pow3<=n){
         pow3 = power(3,k);
         pow3_vi.push_back(pow3);
         sum+=pow3;
         k++;
       }
 
       //for(auto i : pow3_vi) cout<<i<<" ";
       
       lli i = pow3_vi.size()-1, ans;
       while(i >= 0){
         lli temp = sum - pow3_vi[i];
         if(temp < n){
           i--;
         }
         else{
           sum = temp;
           i--;
         }
       }
       
       return sum;
}
  
  int main()
  {
    //write your code here
    int t;cin>>t;
    while(t--){
     
       lli n;cin>>n;
       cout<<"No = "<<goodnumber(n)<<endl;
       
    
    }
    
    return 0;
  }