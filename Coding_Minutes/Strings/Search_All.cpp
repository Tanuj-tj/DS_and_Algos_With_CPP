#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};

    int index = big.find(small);

    if(index==-1){
         return result;
    }
    
    while(index!=-1){
        result.push_back(index); 
        index = big.find(small,index+1);    
    }

    return result;


}

int main(){
    
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
     
    auto ans = stringSearch(bigString,smallString);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}