#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>

pair<int,int> staircaseSearch(int arr[][4],int n,int m,int key){
	
    // Edge case
    if(key < arr[0][0] or key > arr[n-1][m-1]) return {-1,-1};

	int start = 0, end = m - 1;
    
	while(start < n and end >= 0){
		
		if(arr[start][end] == key){
			return {start,end};
		}

		else if(arr[start][end] < key){
			start++;
		}

		else{
			end--;
		}
	}

	return {-1,-1};
}

int main(){
     
    // 2D Row and Column Wise Sorted Array
	int arr[][4] = { {10,20,30,40},
					 {15,25,35,45},
					 {27,29,37,48},
					 {32,33,39,50}};

	int n = 4, m = 4;
    int key = 29;
	auto ans = staircaseSearch(arr,n,m,key);

	cout<<ans.first<<","<<ans.second<<endl;

	return 0;
}