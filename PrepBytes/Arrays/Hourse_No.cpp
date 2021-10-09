#include <bits/stdc++.h>
  using namespace std;
  
  int main()
  {
    //write your code here
    int t; cin>>t;
    
    while(t--){
      
      long long int n; cin>>n;
      
      long long int no_of_digits = 0;
      long long int temp = n;
      
      while(temp){
        int lst = temp % 10;
        no_of_digits += 1;
        temp/=10;
      }
      
      if(no_of_digits == 1){
        cout<<n<<endl;
        continue;
      }
      
      temp = no_of_digits-1; 
      long long int x = 9,y = 1,ans=0;
      while(temp--){
        ans += (x * y);
        x *= 10;
        y++;
      }

      ans += (n - ( pow(10,no_of_digits-1) ) + 1) * no_of_digits;

      cout<<ans<<endl;
      
    }
    
    return 0;
  }