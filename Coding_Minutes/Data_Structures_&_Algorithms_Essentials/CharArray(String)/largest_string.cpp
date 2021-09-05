#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

    // This will consume the first \n character
	cin.get();

	char sentence[1000];
	char largest[1000];

	int largest_len = 0;

	while(n--){
		cin.getline(sentence,1000);
		int len = strlen(sentence);
		if(len > largest_len){
			largest_len = len;
			strcpy(largest,sentence);
		}
	}

	cout<<"Largest sentence is "<<largest << "which is "<<largest_len<<" character long";

	return 0;
}