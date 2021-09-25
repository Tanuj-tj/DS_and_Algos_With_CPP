#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &array,int s,int e){
	
	int x = s;
	int mid = (s + e)/2;
	int y = mid+1;

    vector<int> temp;

	while(x <= mid and y <= e){
		if(array[x] < array[y]){
			temp.push_back(array[x++]);
		}
		else{
			temp.push_back(array[y++]);
		}
	}

	while(x <= mid){
		temp.push_back(array[x++]);
	}
	while(y <= e){
		temp.push_back(array[y++]);
	}

	// Copy the temp array into original array
	int idx = 0;
	for(int i = s ; i <= e ; i++){
		array[i] = temp[idx++];
	}
	return;
}

void mergeSort(vector<int> &array,int s,int e){
	
    // Base Case
	if(s >= e){
		return;
	}

	int mid = (s + e) / 2;
	mergeSort(array,s,mid);
	mergeSort(array,mid+1,e);
	return merge(array,s,e); 

}

int main(){

	vector<int> arr{10,5,2,0,7,6,4};
	int s = 0;
	int e = arr.size()-1;
	mergeSort(arr,s,e);
	for(auto i : arr){
		cout<<i<<" ";
	}

	return 0;
}
