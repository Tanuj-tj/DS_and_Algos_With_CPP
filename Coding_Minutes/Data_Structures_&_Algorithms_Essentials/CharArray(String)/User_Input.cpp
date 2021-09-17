#include<bits/stdc++.h>
using namespace std;

int main(){

	char a[] = {'a','b','h','\0'};
	char b[] = "abh";
	cout<<b<<endl;
	cout<<strlen(b)<<endl; // 3
	cout<<sizeof(b)<<endl; // 4
        
	// Methods for taking User Input
	
	// 1.
	char c[100];
	cin>>c;    // If space is in between a i/p sting then it will consider it as a new line
	cout<<c<<endl;

        // 2.
	char temp = cin.get();

	while(temp != '?'){
		cout<< temp;
		temp = cin.get();
	}
	
	// 3. 
	char sentence[1000];

	cin.getline(sentence,1000);

	cout<<sentence<<endl;
	
	// 4.
	char paragraph[1000];

	cin.getline(paragraph,1000,'.');

	cout<<paragraph<<endl;
   
        // 5.
	
	string str;
	getline(cin, str);
	
	return 0;
}
