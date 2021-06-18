/*
Non-Repeating Character
=======================

You are given a running stream of characters, output the
first non repeating character in the string formed so far
after every new character you get in input. Output -1 if
such a character doesn't exist.

Input       Output
aabccbcd    a-1 b b b-1-1 d


*/

#include<bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){
    
    // Frequency map
    int freq[27] = {0}; // a-z

    // Queue
    queue<char> q;

    vector<char> ans;

    for(auto ch : S){
        
        q.push(ch);
        freq[ch - 'a']++;
        
        // queue -> remove all chars from front of queue till we get a char with freq 1
        while(!q.empty()){
            int idx = q.front() - 'a';
            if(freq[idx] > 1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('0');
        }

    }

    return ans;
}


int main(){
    
    string S = "aabccbcd";
    auto ans = FindFirstNonRepeatingCharacter(S);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}