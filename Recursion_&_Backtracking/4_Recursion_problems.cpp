// ****Recursion**** //

// 1. Sum of N Natural Numbers
// 2. Find a^b 
// 3. Find the no. of ways in nxm matrix
// 4. Josephus problem

#include <iostream>

using namespace std;

// 1. 
int sum(int n){
    if(n==1){
        return 1;
    } 
    return n + sum(n-1);
}

// 2.
int power(int a,int b){
    if(b==0){
        return 1;
    }
    return power(a,b-1) * a;
}

// 3. 
int count_ways(int n,int m){   // n x m matrix
    if(n==1 || m==1){
        return 1;
    }
    return count_ways(n-1,m) + count_ways(n,m-1);
    
}

// 4. 
int jos(int n,int k){
    if(n==1){
        return 0;
    }
    return (jos(n-1,k)+k)%n;
}

int main()
{
    cout<<"Sum of 4 natural nos: "<<sum(4)<<endl;
    
    cout<<"Power of 3^4 is: "<<power(3,4)<<endl;
   
    cout<<"No. of ways in 4x3 Matrix :"<<count_ways(4,3)<<endl;
    
    cout<<"Josephus Problem: with n=5,k=3: "<<jos(5,3)<<endl;
   
   return 0;
}