#include <bits/stdc++.h>
using namespace std;
  
void func(int n){
  
  cout<<n<<" ";
  
  if(n<=0){
    return;
  }
  
  func(n-5);  
  
  cout<<n<<" ";
}  
  
  int main()
  {
    //write your code here
    int t; cin>>t;
    while(t--){
      int n; cin>>n;
      func(n);
      cout<<endl;
    }
    
    return 0;
  }
