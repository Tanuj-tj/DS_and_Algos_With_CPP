/*
Given a string, write a function to replace all sp aces in a
string with '%20'. It is given that the string has sufficient
space at the end to hold the additional characters.

Sample Input :
hello world, how are you?

Sample Output :
hello%20wor1d,%20%20how%20are%20you?

*/

#include<bits/stdc++.h>
using namespace std;

void replace_spaces(char *str){
   
   // Calculate Spaces 
   int space = 0;
   for(int i=0;i<str[i]!='\0';i++){
       if(str[i]==' '){
           space++;
       }
   }
   
   // Set string size to current lenght of string + 2 * spaces present in it
   int idx = strlen(str) + 2*space;
   str[idx] = '\0';

   // Iterate from back 
   for(int i=strlen(str)-1;i>=0;i--){
       if(str[i]==' '){
           // Fill with "%20" => |'%'|'2'|'0'|
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';
            idx = idx - 3;
       }
       else{
           str[idx-1] = str[i];
           idx--;
       }
   }

}

int main(){
    
    char input[10000];
    cin.getline(input,1000);
    replace_spaces(input);
    cout<<input<<endl;
    return 0;
}
