#include <bits/stdc++.h>

using namespace std;

unordered_map<char,int> symbol = {{'{',-1},{'[',-2},{'(',-3},
                                {'}',1},{']',2},{')',3}};
                                
string isBalanced(string s) {
    stack<int> st;
    for(auto i:s){
        if(symbol[i] < 0){
            st.push(i);
        }
        else{
            if(st.empty()) return "NO";
            char top = st.top();
            st.pop();
            if(symbol[top] + symbol[i] != 0) return "NO";
        }
    }
    if(st.empty()) return "YES";
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}