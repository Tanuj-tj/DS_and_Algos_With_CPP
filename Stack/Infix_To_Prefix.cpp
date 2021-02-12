//// INFIX to PREFIX
// (a-b/c)*(a/k-l)

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


// Operator Precidence

/*

` [],{},() ` >> ` ^ ` >> ` /,* ` >> ` +,- `
    
*/
int prec(char ch){
    
    if(ch=='^'){
        return 3;
    }
    else if(ch=='/' || ch=='*'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
    
}

string infixToPrefix(string s){
    
    //Step 1.
    
    // Reverse the given infix expression
    // reverse func is included in <algorithm> header file
    
    reverse(s.begin(),s.end()); 
    
    // Step 2 
    
    // Iterate through the string and change the brackets : ( <=> ) , ) <=> (
    
    string res;
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        // If operator then add to res
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            res+=s[i];
        }
        // If opening brackers then push into stack
        else if(s[i]==')'){ // => '('
            st.push(s[i]);
        } 
        // If closing brackets then pop till the opening bracket is found 
        else if(s[i]=='('){ // => ')'
           while(!st.empty() && st.top()!=')'){
               res+=st.top();
               st.pop();
           }
           // pop the remainig opening bracket
           if(!st.empty()){
               st.pop();
           }
        }
        // Check the presidence of operator
        else{
            while(!st.empty() && prec(st.top()) > prec(s[i])){
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
    
    //Step 3 
    
    // Again reverse the resultant string
    reverse(res.begin(),res.end());
    return res;
} 

int main()
{
   cout<<infixToPrefix("(a-b/c)*(a/k-l)");
   
   return 0;
}
