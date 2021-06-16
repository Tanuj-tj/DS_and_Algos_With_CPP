/*
Given an expression string, write a prpgram to check all the pairs of 
parenthesis are valid .


Input :
((a+b)*x-d)
((a+b]+c*(d-e))

Output :
True
False

*/


#include<bits/stdc++.h>
using namespace std;

bool isBalance(string input){  

    stack<char> s;
    
    for(auto ch : input){

        switch (ch)
        {
        case '(':
        case '[':
        case '{':
                s.push(ch);
                break;
        case ')':
                if(!s.empty() and s.top()=='('){
                    s.pop();
                }
                else{
                    return false;
                }
                break;

        case ']':
                if(!s.empty() and s.top()=='['){
                    s.pop();
                }
                else{
                    return false;
                }
                break;

        case '}':
                if(!s.empty() and s.top()=='{'){
                    s.pop();
                }
                else{
                    return false;
                }
                break;
        
        default:
            continue;
        }
    }
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }


}

int main(){
  
    string s = "((a+b)*x-d)";

    if(isBalance(s)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
	return 0;
}

