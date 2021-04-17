#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 

int first_occurance(vector<int> v,int key){
	int start = 0;
	int end = v.size()-1;
    int mid;
    int first=-1;
	while(start<=end){
		mid = start + (end - start) / 2;

		if(v[mid]==key){
			//return 1;
			 first = mid;
			 end = mid - 1;
		}

		else if(v[mid]>key){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return first;

}

int last_occurance(vector<int> v,int key){
	int start = 0;
	int end = v.size()-1;
    int mid;
    int last=-1;
	while(start<=end){
		mid = start + (end - start) / 2;

		if(v[mid]==key){
			//return 1;
			 last = mid;
			 start = mid + 1;
		}

		else if(v[mid]>key){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return last;

}
  

int main(){

    vector<int> v1 = {1,2,3,4,4,5};
	cout<<first_occurance(v1,4)<<endl;
    cout<<last_occurance(v1,4)<<endl;

	int total = last_occurance(v1,4)-first_occurance(v1,4)+1;
	cout<<total<<endl;
    
	return 0;
    
}
