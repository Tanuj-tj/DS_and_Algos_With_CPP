/*
Given two strings, one big string and one small string, find
the 'smallest window' in the big string that contains all
characters of the small string.

- Window can have additional characters than required.
- If small string has duplicates, then those duplicates must
be pre§ent with same or higher count in window.

Input :
S1 = hello_world 
52 = lol

Output : llo

Input :
s1 = fizzbuzz
s2 = fuzz

output : fizzbu

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        // Store the Frequency of evey letters of t string in a array 
        // or hashmap => unordered_map<char,int> FT;
        // Here we are using Array as a frequency map

        int FT[256] = {0};

        for(int i=0;i<t.length();i++){
            FT[t[i]]++;    //Eg. with hashmap { 'f':1, 'u':1, 'z':2}
        }
        
        // Apply sliding window Algorithm
        
        // Frequency of string
        int FS[256] = {0};
        
        // maintain how many characters have been matched
        int count = 0;  

        int start = 0;
        
        int start_idx = -1;

        int min_so_far = INT_MAX;

        int window_size;
        


        for(int i=0;i<s.length(); i++){

            char ch = s[i];

            FS[ch]++;         //Eg. with hashmap {'f':1,'i':1,'z':4,'b':1,'u':1 }
            
            // Cound how many T strings char have been match till now with S strings char
            if(FT[ch]!=0 and FS[ch] <= FT[ch]){
                count++;
            }

            // If all characters of patterns are found in the current window then you can start contracting
            // This will be achieved when count will reach up till t.length()

            if(count==t.length()){

                // Start contracting from the left to remove unwanted characters

                while(FT[s[start]]==0 or FS[s[start]] > FT[s[start]]){
                    FS[s[start]]--;
                    start++;
                }

                // Note the window size
                window_size = i - start + 1;
                if(window_size < min_so_far){
                    min_so_far = window_size;
                    start_idx = start;
                }
            }

        }

        if(start_idx == -1){
            return "No window found";
        }
        return s.substr(start_idx, min_so_far);

    }
};

int main(){

    Solution *obj = new Solution();
    string s1 = "fizzbuzz";
    string t1 = "fuzz";
    string s2 = "hello_world";
    string t2 = "lol";
    cout<<obj->minWindow(s1,t1)<<endl;
    cout<<obj->minWindow(s2,t2)<<endl;
    
    return 0;
}
