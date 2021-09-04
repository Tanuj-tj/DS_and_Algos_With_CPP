#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;}

// Bubble Sort
void bubble_sort(int arr[],int n){
	
	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < n - i ; j++){
			if(arr[j] > arr[j+1]){
				swap(arr,j,j+1);
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;}

// Insertion Sort
void insertion_sort(int arr[],int n){
	
	for(int i = 1 ; i < n ; i++){
		
		int current = arr[i];
		int prev = i - 1;

		while(prev >= 0 and arr[prev] > current){
			arr[prev+1] = arr[prev];
			prev--;
		}
		arr[prev+1] = current;
	}

	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;}

// Selection Sort
void selection_sort(int arr[],int n){

	for(int pos = 0 ; pos < n-1 ; pos++){

		int current = arr[pos];
		int min_position = pos;

		for(int j = pos ; j < n ; j++){
			if(arr[j] < arr[min_position]){
				min_position = j;
			}
		}
		swap(arr,min_position,pos);
	}

	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;}

// Counting Sort
void counting_sort(int arr[],int n){
    
    int largest = -1;

    for(int i = 0 ; i < n ; i++){
    	largest = max(largest,arr[i]);
    }

    // Dynamic array via poiters
	// int *freq = new int[largest+1]

	// Dynamic array via vector
	vector<int> freq(largest+1,0);

	// update the frequency array
	for(int i = 0 ; i < n ; i++){
		freq[arr[i]]++;
	}

	// Put back the elements from freq into original array
	int j = 0;
	for(int i = 0 ; i <= largest ; i++){
		
        // Update only when the freq is grater then 0
		while(freq[i] > 0){
			arr[j] = i;
			freq[i]--;
			j++;
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


// Inbuilt sorting techniques
// void inbuilt_sort(int arr[],int n){

// 	// Inbuilt sort function
// 	// Defined inside #include<algorithm>
// 	sort(arr,arr+n);

// 	// Inorder to reverse the given array
// 	reverse(arr,arr+n);

// 	// We can write a comparator function for getting the op in descending order
    
// 	bool compare(int a,int b){
// 		return a > b;
// 	}
    
//     // We have to pass function as a parameter to the sort function
// 	sort(arr,arr+n,compare);

// 	// One more way to sort in descending is to use geater<int>()
//     sort(arr,arr+n,greater<int>());	}



int main(){

	int arr[] = {-2,3,4,-1,5,-12,6,1,13};
	int n = sizeof(arr)/sizeof(int);

	cout<<"Bubble Sort"<<endl;
	bubble_sort(arr,n);
	cout<<"Insertion Sort"<<endl;
	insertion_sort(arr,n);
	cout<<"Selection Sort"<<endl;
	selection_sort(arr,n); 

	int arr1[] = {88,97,10,12,15,1,5,6,12,5,8};
	int n1 = sizeof(arr1)/sizeof(int);

	cout<<"Counting Sort"<<endl;
	counting_sort(arr1,n1); 

	return 0;
}
