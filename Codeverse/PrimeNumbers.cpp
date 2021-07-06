/*
Facts about Prime Numbers 
-------------------------

1. Two is the only even prime
2. Every prime can be written as 6b + 1 or 6n - 1, except 2 and 3, n is a natural number
3. Goldbach Conjecture: Every even integer greater then 2 can be expressed as the sum of two primes
4. Wilson's Theorem : (p-1)!=(p-1) mod p
5. 2 and 3 are only consecutive numbers that are prime
*/


#include <bits/stdc++.h>

using namespace std;

// Approach 1 : O(N)

// A no. which has 2 factors is a prime no. ( 1 and itself )
string isPrime1(int num){
    
    int  cnt = 0;

    for(int i = 1 ; i <= num; i++){
        
        if(num % i == 0){
            cnt++;
        }
    }
    
    if(cnt == 2) return "Prime No";
    else return "Not a Prime No";
}

// Approach 2 : O(sqrt(N))

string isPrime2(int num){
    
    int  cnt = 0;

    for(int i = 1 ; i <= sqrt(num) ; i++){
        
        if(num % i == 0){
            cnt+=2;
        }
    }
    
    if(cnt == 2) return "Prime No";
    else return "Not a Prime No";
}

int main()
{
    cout<<isPrime1(11)<<endl;
    cout<<isPrime2(11)<<endl;
    
    return 0;
}
