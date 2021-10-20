#include <bits/stdc++.h>
#define ll long long int
using namespace std;

char firstNonRepeatingChar(string str){
	int arr[26] = {0};

	for(int i = 0 ; i < str.length() ; i++){
		arr[str[i] - 97]++;
	}
	
	for(int i = 0 ; i < str.length() ; i++){
		if(arr[str[i] - 97] == 1){
			return str[i];
		}
	}
}

int main()
{	
  string str = "bcadbcae";
  cout<<firstNonRepeatingChar(str)<<endl;

  return 0;
}
