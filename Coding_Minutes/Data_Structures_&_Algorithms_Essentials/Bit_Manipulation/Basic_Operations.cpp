#include<bits/stdc++.h>
using namespace std;

// Get ith bit

int getIthBit(int n,int i){
	int mask = (1<<i);
	return (n & mask) > 0 ? 1 : 0;
}

// Clear ith bit

int clearIthBit(int n,int i){
	// int mask = ~(1<<i);
	// n = n & mask;

	n = n & ~(1<<i);
	return n;	
}

// Set ith bit

int setIthBit(int n,int i){
	int mask = (1<<i);
	n = n | mask;
	return n;
}

// Update Ith bit

int updateIthBit(int n,int i,int v){
	
    // Clear ith bit Bit
	n = n & ~(1 << i);
	int mask = (v << i);
	n = n | mask;
	return n;

}

// Clear Last Ith Bit

int clearLastIthBit(int n,int i){
	int mask = (-1 << i);
	n = n & mask;
	return n;
}

int main(){

	int n = 13;
	int i = 1;
	int v = 1;

	cout<<getIthBit(n,i)<<endl;

	cout<<clearIthBit(n,i)<<endl;

	cout<<setIthBit(n,i)<<endl;

	cout<<updateIthBit(n,i,v)<<endl;
    
    int n1 = 15;
    int i1 = 2;
	cout<<clearLastIthBit(n1,i1)<<endl;

	return 0;
}
