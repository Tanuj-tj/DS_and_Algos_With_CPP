#include <bits/stdc++.h>
using namespace std;
     
/*   
Link : https://leetcode.com/problems/string-compression/

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

*/

int compress(vector<char>& chars) {
    // your code goes here

    int n = chars.size();
        int i = 0 , index = 0;
        while(i < n){
            int j = i;
            while(j < n and chars[i] == chars[j]){
                j++;
            }
            chars[index++] = chars[i];
            if(j-i > 1){
                string s = to_string(j - i);
                for(char i:s){
                    chars[index++] = i;
                }
            }
            i = j;
        }
        
        return index;
}

int main(){
    
    vector<char> chars1{'a','a','b','b','c','c','c'};
    cout<<compress(chars1)<<endl;

    vector<char> chars2{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout<<compress(chars2)<<endl;

	return 0;
}
