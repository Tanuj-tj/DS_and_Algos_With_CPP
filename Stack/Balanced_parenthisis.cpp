//// BALANCED PARANTHISIS
// "{[()]}"

#include <iostream>
#include <stack>

using namespace std;

bool isvalid(string s){
    int n = s.size();
    stack<char> st;
    bool ans = true;
    
    for(int i=0;i<n;i++){
        if(s[i] == '{' or s[i] == '(' or s[i] == '['){
            st.push(s[i]);
        }
        else if(!st.empty() and s[i] == ')'){
            
            if(st.top()=='('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(!st.empty() and s[i] == '}'){
            
            if(st.top()=='{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
        else if(!st.empty() and s[i] == ']'){
            
            if(st.top()=='['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return ans;
}

int main()
{
    
   string s = "{[()]}";
   string res = isvalid(s) ? "Valid!!": "Invalid!!";
   cout << res;
   
   return 0;
}
