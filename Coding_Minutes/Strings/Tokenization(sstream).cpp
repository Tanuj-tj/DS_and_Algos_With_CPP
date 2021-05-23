#include<bits/stdc++.h>
using namespace std;

// Using sstream

int main(){

    string input;
    getline(cin,input);  // "this is a sunny day"

    // String stream object 
    // It suppoers >> and << operators 
    // It behaves like a buffer which helps to read and write data

    stringstream ss(input);

    string token;  // "this"  "is" "a" "sunny" "day"
    vector<string> tokens; 
    
    while(getline(ss,token,' ')){
        cout<<token<<" ";
        tokens.push_back(token);
    }
    cout<<endl;
   // cout<<token<<endl;
    
    for(auto i:tokens){
        cout<<i<<", ";
    }
    return 0;
}