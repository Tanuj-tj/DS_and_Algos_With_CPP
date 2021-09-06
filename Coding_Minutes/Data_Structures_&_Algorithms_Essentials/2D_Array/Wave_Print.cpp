#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>

vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    // your code goes here
	int top = 0, down = m-1 , left = 0, right = n-1, temp = 1, check = n;
    vi ans;
  
    while(check){
    	if(temp == 1){
    		for(int i = top ; i <= down ; i++){
				ans.push_back(arr[i][right]);
			}
			temp = 0;
			right--;
			check--;
    	}
    	else{
    		for(int i = down ; i >= top ; i--){
				ans.push_back(arr[i][right]);
			}
			temp = 1;
			right--;
			check--;		
    	}
	
   }
	return ans;


}

int main(){

	vii v{{1,2,3,4},
		  {5,6,7,8},
		  {9,10,11,12},
  		  {13,14,15,16}};

  	int m = v.size() ,n = v[0].size();

	auto ans = WavePrint(m,n,v);
	for(auto i : ans){
		cout<<i<<" ";
	}

	return 0;
}
