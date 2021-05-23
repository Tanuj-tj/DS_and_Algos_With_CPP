#include<bits/stdc++.h>
using namespace std;

// Using strtok

int main(){

    char input[1000];
    cin.getline(input,1000);

    // cout<<strtok(input," ")<<endl;
    // cout<<strtok(NULL," ")<<endl;
    // cout<<strtok(NULL," ")<<endl;
    // cout<<strtok(NULL," ")<<endl;
    // cout<<strtok(NULL," ")<<endl;

    char *token = strtok(input," ");
    cout<<token<<endl;

    while(token!=NULL){
        token = strtok(NULL," ");
        cout<<token<<endl;
    }
   
    return 0;
}