#include<bits/stdc++.h>
using namespace std;

int main(){

	char number[][10] = {
		"one",  // {'o','n','e'},
		"two",   // {'t','w','o'},
		"three",
		"forty",
		"eight",
		"hundred"
	};

	int i = 3;
	cout<<number[i]<<endl;
	cout<<number[i][3]<<endl;

	for(int i = 0 ; i < 6 ; i++){
		cout<<number[i]<<endl;
	}

	string str;

    getline(cin, str,'.');
    cout << "Hello, " << str
         << " welcome to GfG !\n";


	return 0;
}
