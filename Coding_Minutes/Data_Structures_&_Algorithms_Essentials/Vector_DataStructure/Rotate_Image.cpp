/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees
(clockwise).

You have to rotate the image in—place, which means you have to modify the input 2D matrix
directly. DO NOT allocate another 2D matrix and do the rotation.

Sample Input : matrix = [[1,2,3],[4,5,6],[7,8,9]]
Sample Output : [[7,4,1],[8,5,2],[9,6,3]]

Constraints:
* matrix.length == n
* matrix[i].length == n
* 1 <= n <= 20
* -1000 <= matrix[i][j] <= 1000

*/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    // your code goes here

	int n = matrix.size();

    // Transpose 
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1 ; j < n ; j++){
			 swap(matrix[i][j], matrix[j][i]);
		}
	}

	// Row wise revese operation
	for(int i = 0 ; i < n ; i++){
		reverse(matrix[i].begin(), matrix[i].end());
	}
      
}

int main(){

	vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
	rotate(matrix);

	for(auto i : matrix){
		for(auto j : i){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}