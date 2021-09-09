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
template<typename T>
class Vector{
	
	// Data Members
	T *arr;
	int cs;   // Current Size
	int ms;   // Max Size

	// Constructor
public:
	Vector(int max_size = 1){
		cs = 0;
		ms = max_size;
		arr = new T(ms);
	}

	//Methods

	void push_back(const T d){
		if(cs==ms){
			// Create a new array , delete the old one and Double the capacity
			T *old_arr = arr;
			ms = 2*ms;
			arr = new T(ms);
            
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

	T front() const{
		return arr[0];
	}

	T back() const{
		return arr[cs-1];
	}

	T at(const int i) const{
		return arr[i];
	}

	int size() const{
		return cs;
	}

	int capacity() const{
		return ms;
	}

	T operator[](const int i) const{
		return arr[i];
	}
};
