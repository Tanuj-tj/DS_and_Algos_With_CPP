#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>

/*
Write a function that takes in nxm 2D Array,
and prints all arrays elements in a spiral order.
Starting from top left corner goes to right
proceeds in a spiral pattern until every element
is visible

Input :

1  2  3  4 
5  6  7  8
9  10 11 12
13 14 15 16

Output :
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

vi spiralPattern(vii v){
    
	int top = 0, down = v.size()-1 , left = 0, right = v[0].size()-1;
    int dir = 0;
    vi ans;
   
	while(top <= down and left <= right){
		if(dir==0){
			for(int i = left ; i <= right ; i++){
				ans.push_back(v[top][i]);
			}
			top++;
		}
		else if(dir==1){
			for(int i = top ; i <= down ; i++){
				ans.push_back(v[i][right]);
			}
			right--;
		}
		else if(dir==2){
			for(int i = right ; i >= left ; i--){
				ans.push_back(v[down][i]);
			}
			down--;
		}
		else{
			for(int i = down ; i >= top ; i--){
				ans.push_back(v[i][left]);
			}
			left++;

		}
		dir = (dir + 1) % 4;

	}

	return ans;
	
}

int main(){
	vii v{{1,2,3,4},
		   {5,6,7,8},
		   {9,10,11,12},
		   {13,14,15,16}};

	auto ans = spiralPattern(v);
	for(auto i : ans) cout<<i<<" ";

	return 0;
}