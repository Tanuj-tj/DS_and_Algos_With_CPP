#include<bits/stdc++.h>
using namespace std;

int main(){

	char a[] = {'a','b','h','\0'};
	char b[] = "abh";
	cout<<b<<endl;
	cout<<strlen(b)<<endl; // 3
	cout<<sizeof(b)<<endl; // 4

	char c[100];
	cin>>c;    // If space is in between a i/p sting then it will consider it as a new line
	cout<<c<<endl;


	char temp = cin.get();

	while(temp != '?'){
		cout<< temp;
		temp = cin.get();
	}
   

	return 0;
}
