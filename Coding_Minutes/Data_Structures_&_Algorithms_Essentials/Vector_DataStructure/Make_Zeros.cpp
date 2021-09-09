/*
Given a two-dimensional array, if any element within is zero, 
make its whole row and column zero. 
For example, consider the matrix below.

Sample Input :

{ {5, 4, 3, 9}, 
  {2, 0, 7, 6}, 
  {1, 3, 4. 0}, 
  {9. 8, 3, 4} }

Sample Output :

{ {5, 0, 3, 0}, 
  {0, 0, 0, 0}, 
  {0, 0, 0, 0}, 
  {9, 0, 3, 0} }

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){

	vector<int> r,c;   // {1,2} {1,3}
    int n = arr.size();
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < arr[i].size() ; j ++){
			if(arr[i][j] == 0){
				r.push_back(i);
				c.push_back(j);
			}
		}
	}

	for(auto fixed : r){
		for(int i = 0 ; i < n ; i++){
			arr[fixed][i] = 0;
 		}
	}

	for(auto fixed : c){
		for(int i = 0 ; i < n ; i++){
			arr[i][fixed] = 0;
 		}
	}

	return arr;

}

int main(){

	vector<vector<int>> arr{ {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 9}, {9, 8, 3, 4} };

	auto ans = makeZeroes(arr);

	for(auto i : ans){
		for(auto j : i){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}