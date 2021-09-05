#include<bits/stdc++.h>
using namespace std;

int main(){

	char a[1000] = "apple";
	char b[1000];
    
    // Calcualte length
	cout<<"strlen() : " <<strlen(a)<<endl;

    // String copy 
    strcpy(b,a);
    cout<<b<<endl;

    // Compare
    cout<< strcmp(a,b)<<endl;

    char web[] = "www.";
    char domain[] = "linkdin.com";
     
    // String concatenation
    cout<<strcat(web,domain)<<endl;
   

	return 0;
}
