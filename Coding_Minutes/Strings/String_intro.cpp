#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  
    // Ways to Represent string
   
    // char s[1000] = {'H','E','L','L','O'};

    string s = "HELLO";
   
    string s1;

    // User input 
    //getline(cin,s1);

    for(char ch:s){
        cout<< ch<<" ";
    }
    cout<<s<<endl;

     // Take multiple string as a input
    /*
    int n = 5;
    vector<string> sarr;
    while(n--){
        string temp;
        getline(cin,temp);
        sarr.push_back(temp);
    }

    for(string ch:sarr){
        cout<<ch<<" ";
    }

    */

    return 0;
}
