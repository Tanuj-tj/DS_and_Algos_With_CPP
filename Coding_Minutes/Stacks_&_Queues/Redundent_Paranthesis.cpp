/*
Redundant Paranthesrs
=====================

Given a string of balanced expression, find if it contains a
redundant parenthesis or not. A set of parenthesis are
redundant if same sub-expression is surrounded by
unnecessary or multiple brackets. Print ‘Yes’ if redundant
else 'No'.

Input : 
((a+b)) 
(a+(b)/c)
(a+b*(c-d))

Output :
Yes
Yes
No

*/

#include<bits/stdc++.h>
using namespace std;

bool checkRedundent(string str){

    stack<char> s;

    for(char ch:str){

        if(ch!=')'){ 
            s.push(ch);
        }
        else{ 
            // ch == ')'
            
            bool operator_found = false;
            
            while(!s.empty() and s.top()!='('){
                char top = s.top();
                if(top=='+' or top=='-' or top=='*' or top=='/'){
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();

            if(operator_found == false){
                return true;
            }
        }
    }

    return false;
}


int main(){
    
    string str = "(a+b*(c-d))";
    if(checkRedundent(str)){
        cout<<"Contains Redundent Paranthesis";
    }
    else{
        cout<<"Doesn't contain Redundant Paranthesis";
    }
    return 0;
}