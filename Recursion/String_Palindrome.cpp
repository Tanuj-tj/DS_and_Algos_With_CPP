//// String Palindrome
// 1. Palindome String
// 2. Print the Subset of a given string
// 3. Permutation of a given string

#include <iostream>
using namespace std;

// 1.
bool isPalindrome(string s,int l,int r){
    if(l>=r){
        return true;
    }
    if(s[l]!=s[r]){
        return false;
    }
    return isPalindrome(s,l+1,r-1);
}

// 2.
void powerset(string s,int i,string cur){
    if(i==s.length()){
        cout<<cur<<endl;
        return;
    }
    powerset(s,i+1,cur+s[i]);
    powerset(s,i+1,cur);
}

// 3.

void permute(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permute(ros,ans+ch);
    }
}

int main(){
    
    string s = "racecar";
    cout<<isPalindrome(s,0,s.length()-1)<<endl;
    
    string s1 = "abc";
    powerset(s1,0,"");
  
    string s2 = "abc";
    permute(s2,"");
    return 0; 
}
