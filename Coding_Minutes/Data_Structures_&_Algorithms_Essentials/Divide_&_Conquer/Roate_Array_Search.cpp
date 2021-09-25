#include <bits/stdc++.h>
using namespace std;

// Not A very good approach 
int BinarySearch(vector<int> arr,int k,int s,int e){
	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid]==k) return mid;
		else if(arr[mid] > k) e = mid - 1;
		else s = mid + 1;
	}
	return -1;
}

int rotateSearch(vector<int> arr,int k,int s,int e){
   
	int mid = (s+e)/2;

	if(arr[mid] == k){
		return mid;
	}
	else if(arr[s] < arr[mid]){
		int res = BinarySearch(arr,k,s,mid);
		if(res != -1) return res;
		else{
			return rotateSearch(arr,k,mid+1,e);
		}
	}
	else if(arr[mid] < arr[e]){
		int res = BinarySearch(arr,k,mid,e);
		if(res != -1) return res;
		else{
			return rotateSearch(arr,k,s,mid-1);
		}	
	}
}

// Better Approach
int rotateSearch1(vector<int> arr,int k){

	int s = 0 , e = arr.size()-1;

	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid] == k) return mid;
		
		// 2 cases
		if(arr[s] <= arr[mid]){

			if(arr[s]<=k and arr[mid]>k){
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}
		}
		else{

			if(arr[mid+1]<=k and arr[e]>=k){
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}
		}
	}

	return -1;
}

int main(){
	vector<int> arr{4,5,6,7,0,1,2,3};
	int k = 5;
	int s = 0,e = arr.size()-1;
	cout<<rotateSearch(arr,k,s,e)<<endl;
	cout<<rotateSearch1(arr,k)<<endl;

	return 0;
}
