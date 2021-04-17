#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 

bool binary_search(vector<int> v,int key){

	int start = v[0];
	int end = v[v.size()-1];
        int mid;
	while(start<=end){
		mid = start + (end - start) / 2;

		if(v[mid]==key){
			return true;
		}

		else if(v[mid]>key){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}
	return false;

}

int main(){
    
    vector<int> v = {1,2,3,4,5,6};
    cout<<binary_search(v,4)<<endl;

	return 0;
    
}