#include<bits/stdc++.h>
using namespace std;

// Given a sentence found the no. of alphabates, spaces, digits 

int main(){

    char ch;
    ch = cin.get();

    //count
    int alpha = 0;
    int space = 0;
    int digit = 0;

	while(ch != '#'){
	    
  		if(ch >= '0' and ch <= '9') digit++;

  		else if(ch >= 'a' and ch <= 'z') alpha++;

  		else if(ch == ' ' or ch == '\t') space++;

		ch = cin.get();
	}

	cout<<"Total alphabets : "<<alpha<<"\nTotal spaces : "<<space<<"\nTotal Digits : "<<digit<<endl;
   

	return 0;
}
