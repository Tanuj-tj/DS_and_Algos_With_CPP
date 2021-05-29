/*
You are building a logic for a clock that requires you convert absolute time in minutes into a
format supported by a digital clock. See examples below.

Input :
Input is a single integer.
1180

Output :
Output is a string denoting the digital clock time.
19:40
*/

#include<bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes){

    // Check if the value of minutes is divisible with 60
    // if not minutes-- and count++ and again check and repeat the process
    // the count will be the minutes and the remaining minutes/60 will be hours => hours:mins
  
    int min_count = 00;
        while(minutes){
            if(minutes % 60 == 0){
                if(min_count<10){
                    return to_string(minutes / 60)+":0"+to_string(min_count);    
                }
                return to_string(minutes / 60)+":"+to_string(min_count);
            }
            else{
                minutes--;
                min_count++;
            }
        }
}
int main(){

    int minutes;cin>>minutes;

    cout<<convert_to_digital_time(minutes)<<endl;
    
    return 0;
}
