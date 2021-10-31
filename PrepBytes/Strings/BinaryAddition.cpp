/*
Steps:
1. Start from the last binary character
2. Keep a carry var initially set to 0
3. keep string res += carry + s1[last] + s2[last]
4. 4 results can be obtained 0,1, 2, 3
5. if res is > 1 than carry will be 1 otherwise 0
6. if the res will be even then append 0 otherwise 1


*/

#include <bits/stdc++.h>
  using namespace std;
  
string binaryAdditon(string a,string b){
   int i = a.length()-1 , j = b.length()-1;

    int carry = 0;
    
    string result;

    while(i>=0 or j>=0){
      int sum = carry;
      if(i>=0) sum += a[i--] - '0';
      if(j>=0) sum += b[j--] - '0';
      carry = sum > 1 ? 1:0;
      // Even Case = 0
      // Odd Case = 1
      result += to_string(sum%2);
    } 
    if(carry) result += to_string(carry);
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
  //write your code here
  int t; cin>>t;
  while(t--){
    string a; cin>>a;
    string b; cin>>b;
    cout<<binaryAdditon(a,b)<<endl;
  }
  
  return 0;
}
