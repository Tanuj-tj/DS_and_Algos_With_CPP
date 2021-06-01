/*
Given a string write a function to find the largest substring with unique
characters (no duplicates)

Sample Input :
prateekbhaiya
aabcb

Sample Output :
ekbhaiy
abc

*/


#include<bits/stdc++.h>
using namespace std;

class Substring{
    public:

    string unique_substring(string str){

        int i=0,j=0;
        int window_len = 0;
        int max_window_len = 0;
        int start_window = -1;

        unordered_map<char,int> m;

        while(j<str.length()){
        
            char ch = str[j];
            
            // if the current char is not in hashmap 
            if(m.count(ch) and m[ch]>=i){
                i = m[ch] + 1;
                window_len = j - i; // Update remaining window lenght excluding current character
            }

            // Upadate the last occurance
            m[ch] = j;
            window_len++;
            j++;

            // update max_window_len at every step
            if(window_len > max_window_len){
                max_window_len = window_len;
                start_window = i;
            }    

        }

        return str.substr(start_window, max_window_len);

    }
};

int main(){
    string str1 = "prateekbhaiya";
    string str2 = "aabcb";
    Substring *obj = new Substring();
    cout<<obj->unique_substring(str1)<<endl;
    cout<<obj->unique_substring(str2)<<endl;
    return 0;
}




/*--------------------------------------------------------------------

// Dry Run :

string unique_substring(string str){
   
    //Eg. "a  b  c  a  b  e  b" 
    //     0  1  2  3  4  5  6
  
	int i = 0;  // 0 , 1 , 2
	int j = 0;  // 0 , 1 , 2 , 3, 4 , 5, 6

	int window_len = 0;  // 0, 1, 2 , 3 , 2 , 3 , 2, 3,4 , 1 , 2
	int max_window_len = 0;  // 0 , 1 , 2, 3, 4
	int start_window = -1;  // -1 , 0 , 2


	unordered_map<char,int> m;  // {'a': 3, 'b': 4, 'c':2,'e':5}

    // str.length() = 7
	while(j < str.length()){  // T , T , T, T , T , T , T

		char ch = str[j];  // a  , b , c, a , b, e , b

		//if it is inside hashmap & its idx >= start of the current window
		if(m.count(ch) and m[ch]>=i){  // F , F , F, T, F,T
			//later on..
			i = m[ch] + 1; // 0 + 1 = 1 , 1 + 1 = 2 , 4+1 = 5
			window_len = j - i; // 3-1 = 2 , 4 - 2 = 2 , 6 - 5 = 1
		}

		//update the last occ 
		m[ch] = j;  //  {'a': 3, 'b':6 , 'c':2, 'e':5}
		window_len++; // 1 , 2 , 3, 3, 3,4, 2
		j++; // 1 ,2 , 3 , 4, 5,6 , 7

		//update max_window_len at every step
		if(window_len > max_window_len){ // T , T , T , F ,T ,
			max_window_len = window_len;  // 1 , 2, 3, 4
			start_window = i;  // 0 ,0, 0,2
		}
	}
	return str.substr(start_window,max_window_len);
}


-------------------------------------------------------------------------*/
