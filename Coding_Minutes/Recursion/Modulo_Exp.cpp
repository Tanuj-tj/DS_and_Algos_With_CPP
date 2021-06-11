/*
Modulo Exponentlatlon
=====================

You are given two numbers a and b, your task is to compute a raised to power b.
As this value can be very large compute it to modulo 1000000007.

HINT: Use Modulo Properties

(m * n) % p has a very interesting property:
(m * n) % p =((m % p) * (n % p)) % p

Expected Time Complexity:

0(log b)

Input Format:

In the function, 2 integers a and b are passed.

Output Format:

Return a single integer which is equivalent to a raised to the power b modulo 1000000007.
Constraints:

1 <=a, b< =50

Sample Testcase:

Input :
5 3
Output:
125

*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 1e18
#define pb push_back
#define vi vector<int>
#define vs vector<string>

ll M = 1000000007;

ll powerModulo(int a, int b){
    
    if(b==0){
        return 1;
    } 
    
    return (a * powerModulo(a,b-1)) % M;
    
}

int main(){
    
    int a = 50,b = 30;
    cout<<powerModulo(a,b);
	return 0;
}