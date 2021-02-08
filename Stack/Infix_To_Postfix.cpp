// INFIX TO POSTFIX
// IP : "(a - b / c) * (a / k - l)"
// OP : " a b c / - a k / l - * "

#include <iostream>
#include <stack>

using namespace std;

// Defining precisions for each operator 
int prec(char ch){

    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

// Infix to postfix
string infixtoPostfix(string s){
    stack<char> st;
    string res;
    
    for(int i=0;i<s.length();i++){
        
        // Operand
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        // Opening Brackets "("
        else if(s[i]=='('){
            st.push(s[i]);
        }
        // Closing Brackets ")"
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        // Operator => Check for precision
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}



int main()
{
    cout<<infixtoPostfix("(a-b/c)*(a/k-l)");   
   
   return 0;
}

