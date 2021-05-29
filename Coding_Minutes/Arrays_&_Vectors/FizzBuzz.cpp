/* 
Write a Fizzbuzz function that returns a vector<string> with the numbers from 1 to n with
the following restrictions:

* for multiples of 3 store "Fizz" instead of the number

* for multiples of 5 store "Buzz" instead of the number

* for numbers which are multiples of both 3 and 5 store "FizzBuzz"
You may use the std: :to_str‘ing(number‘) method to convert a number into a string.   
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    vector<string> ans;
    for(int i=1;i<=n;i++){  
        if((i%3)==0){
            if((i%15)==0){
                ans.push_back("FizzBuzz");
            }
            else{
                ans.push_back("Fizz");
            }    
        }
        else if((i%5)==0){
            ans.push_back("Buzz");
        }
        else{
            ans.push_back(to_string(i));
        }
    }

    return ans;

}

int main(){
    int n=15;
    vector<string> ans = fizzbuzz(n); 
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
