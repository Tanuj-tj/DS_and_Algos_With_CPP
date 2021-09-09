#include<bits/stdc++.h>
using namespace std;

/*
Class :
	Vector

Functions :
	front()
	back()
	size()
	capacity()
*/

// Creating a new data structure
class Vector{
	
	// Data Members
	int *arr;
	int cs;   // Current Size
	int ms;   // Max Size

	// Constructor
public:
	Vector(int max_size = 1){
		cs = 0;
		ms = max_size;
		arr = new int(ms);
	}

	//Methods

	void push_back(const int d){
		if(cs==ms){
			// Create a new array , delete the old one and Double the capacity
			int *old_arr = arr;
			ms = 2*ms;
			arr = new int(ms);
            
            // Copy the elements
			for(int i = 0 ; i < ms ; i++){
				arr[i] = old_arr[i];
			}
            
            // Delete 
			delete [] old_arr;
		}

		arr[cs] = d;
		cs++;
	}

	void pop_back(){
		if(cs>=0){
			cs--;
		}
	}

	bool isEmpty() const{
		return cs==0;
	}

	int front() const{
		return arr[0];
	}

	int back() const{
		return arr[cs-1];
	}

	int at(const int i) const{
		return arr[i];
	}

	int size() const{
		return cs;
	}

	int capacity() const{
		return ms;
	}

	int operator[](const int i) const{
		return arr[i];
	}
};

int main(){

	Vector v(5);

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
