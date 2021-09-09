#include<bits/stdc++.h>
#include "Vector_Class.h"
using namespace std;

int main(){

	Vector<int> v(5);

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	v.pop_back();
	
	cout<<"Front Element "<<v.front()<<endl;
	
	cout<<"Back Element "<<v.back()<<endl;
	
	cout<<"Element at 2nd index "<<v.at(2)<<endl;
	
	cout<<"Vector size "<<v.size()<<endl;   // 5
	cout<<"Vector capacity "<<v.capacity()<<endl;  // 10;
	
	cout<<v.size()<<endl;   // 5
	cout<<v.capacity()<<endl;  // 10;

	for(int i = 0 ; i < v.size() ; i++){
		//cout<<v.at(i)<<",";
		cout<<v[i]<<",";
	}

	return 0;
}
