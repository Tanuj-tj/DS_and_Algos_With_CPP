class Solution {
public:
    
    vector<string> ans;
    
    void generate(int n, string &str, int open ,int close){
          if(open==0 && close==0){
              ans.push_back(str);
              return;
          }
        
          if(open>0){
              str.push_back('(');
              generate(n,str,open-1,close);
              str.pop_back();
          }
        
          if(close>0){
              if(open<close){
                  str.push_back(')');
                  generate(n,str,open,close-1);
                  str.pop_back();
              }
          }
    } 
    
    vector<string> generateParenthesis(int n) {
        string str;
        generate(n,str,n,n);
        return ans;
    }
};
