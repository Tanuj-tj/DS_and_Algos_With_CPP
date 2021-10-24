#include <bits/stdc++.h>
  using namespace std;
  
  int main()
  {
    //write your code here
    int t; cin>>t;
    while(t--){
      string s; cin>>s;
      
      int arr[26] = {0};
      
      for(int i = 0 ; i < s.length() ; i++){
        arr[s[i] - 'a']++;
      }
      
      bool flag = true;
      for(int i = 0 ; i < 26 ; i++){
        if(arr[i] > 1){
          cout<<char(i + 'a')<<"="<<arr[i]<<" ";
          flag = false;
        }
      }
      
      if(flag) cout<<-1;
      
      cout<<endl;
    }
    
    return 0;
  }
