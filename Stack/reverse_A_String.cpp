// Reverse a sentence using stack

// I/P : "Hey, how are you doing ?"
// O/P : "doing ? you are how Hey,"

#include <iostream>
#include <stack>  // Included with c++ STL
#include <string>

using namespace std;

void reverseSentence(string s){
stack<string> st;

for(int i=0;i<s.length();i++){
    
    string word = "";
    
    while(s[i]!=' ' && i<s.length()){
        word+=s[i];
        i++;
    }
    st.push(word);
}

while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}
cout<<endl;
}
int main()
{
   string s = "Hey, how are you doing ?";
   reverseSentence(s);
   
   return 0;
}
