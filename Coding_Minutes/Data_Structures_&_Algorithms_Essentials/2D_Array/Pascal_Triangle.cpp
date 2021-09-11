/*
Given n

print the first n rows of pascal's triangle

1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1

The question might be framed as :

1. Print the first n rows
2. Print the nth row only
3. A row no. and a column no. is given we have to print the element
   
    => Ans will be r-1 
                      C
                        c-1 


Things need to be observed :

1. Initialize the 1st row with 1 then the
   1st and the last column is always 1 .

2. The middle elements are formed by adding its above 2 elements.

3. When we are at the nth row the pascle triangle will alwas have
   n column .
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printPascal(int n)
{
    // your code goes here

    vector<vector<int>> ans(n);
    
    for(int i = 0 ; i < n ; i++){
    	ans[i].resize(i+1);
    	ans[i][0] = ans[i][i] = 1;

    	for(int j = 1 ; j < i ; j++){
			ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
    	}
    }

    return ans;


}

int main(){

	int n;cin>>n;
	auto ans = printPascal(n);
	for(int i = 0 ; i < ans.size() ; i++){
		for(int j = 0 ; j <ans[i].size() ; j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}

	return 0;
}