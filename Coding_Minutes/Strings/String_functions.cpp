#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

    string paragraph = "We are here to learn about STL String. STL strinng class is quite powerful";
   
    string word;
    getline(cin,word);

    // Find Function
    cout<<paragraph.find(word)<<endl;

    // See the fist and second occurances of a word in paragraph

    int index = paragraph.find(word);

    if(index!=-1){
        cout<<"First occ "<<index<<endl;
    }

    index = paragraph.find(word,index+1);
    if(index!=-1){
        cout<<"Second occ "<<index<<endl;
    }
    

    return 0;
}