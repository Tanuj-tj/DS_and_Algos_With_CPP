#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void addTwoNumStr(string str1, string str2){
	
	// Check for the greater string
	if(str1.length() > str2.length()){
		swap(str1,str2);
	}

  cout<<"str1 : "<<str1<<" "<<"Str2 : "<<str2<<endl;

  // reverse both strings
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());
  
  int n1 = str1.length();
  int n2 = str2.length();

  int carry = 0;
  string ans;

  for(int i = 0 ; i < n1 ; i++){
  	int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
  	ans.push_back(sum % 10 + '0');
  	carry = sum / 10;
  }

  for(int i = n1 ; i < n2 ; i++){
  	int sum = ((str1[i] - '0') + carry);
  	ans.push_back(sum % 10 + '0');
  	carry = sum / 10;
  }

  // If some carray is left at the end
  if(carry){
  	ans.push_back(carry + '0');
  }
  
  reverse(ans.begin(), ans.end());

  cout<<ans<<endl;

}

int main()
{	

	int t;cin>>t;
	while(t--){
		string str1; cin>>str1;
  	string str2; cin>>str2;

  	addTwoNumStr(str1,str2);
	}
 
  //cout<<to_string(stoi(str1) + stoi(str2));

  return 0;
}
