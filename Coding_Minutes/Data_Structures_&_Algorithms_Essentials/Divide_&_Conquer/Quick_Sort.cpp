#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &array,int s,int e){
	
	int pivot = array[e];
	int i = s-1;

	for(int j = s ; j < e ; j++){
		if(pivot > array[j]){
			i++;
			swap(array[i],array[j]);
		}
	}

	swap(array[e],array[i+1]);
	return i+1;
}

void quickSort(vector<int> &array,int s,int e){
	
    // Base Case
    if(s>=e) return;

    // Recursive Case
    int pivot = partition(array,s,e);
    quickSort(array,s,pivot-1);
    quickSort(array,pivot+1,e);
}

int main(){

	vector<int> arr{10,5,2,0,7,6,4};
	int s = 0;
	int e = arr.size()-1;
	quickSort(arr,s,e);
	for(auto i : arr){
		cout<<i<<" ";
	}

	return 0;
}
