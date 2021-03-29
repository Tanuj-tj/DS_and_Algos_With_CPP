#include<bits/stdc++.h>
using namespace std;


vector<int> Stock_Spam(vector<int> &arr){
 	vector<int> v;
 	stack<pair<int,int>> s;  // {value , index}
    
    for(int i=0;i<arr.size();i++){
    	if(s.size() == 0){
    		v.push_back(-1);
    	}
    	else if(s.size() > 0 && s.top().first > arr[i]){
    		v.push_back(s.top().second);
    	}
    	else if(s.size() > 0 && s.top().first <= arr[i]){
    		while(s.size() > 0 && s.top().first <= arr[i]){
    			s.pop();
    		}
    		if(s.size()==0){
    			v.push_back(-1);
    		}
    		else{
    			v.push_back(s.top().second);
    		}
    	}
    	s.push({arr[i],i});  // {100 , 0} || 
    }

    for(int i=0;i<v.size();i++){
    	v[i] = i - v[i];
    }

    return v;

}

int main(){
    
    vector<int> arr = {100,80,60,70,60,75,85};

    cout<<"Input :";
    for(int i=0;i<arr.size();i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Output : ";
    for(int i=0;i<Stock_Spam(arr).size();i++){
    	cout<<Stock_Spam(arr)[i]<<" ";
    }

	return 0;
}
