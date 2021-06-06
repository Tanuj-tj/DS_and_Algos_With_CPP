/*
Square Roots
============

Given an integer N and an integer P, you need find the
square root of number N upto P places. Do it without
using a library function. 

Input:
N = 10, P = 3

Output : 
3.162

Approach :
=> Combine binary + Linear Search
   - Complexity : O(LogN + 9P)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vii vector<int,int>
#define vi vector<int>

float square_root(int N,int P){

   int s = 0;
   int e = N;
   float ans = 0;

   // Binary search for getting the interger value 0.....N
   while(s<=e){
       int mid = (s + e)/2;
       
       if(mid*mid==N){
           return mid;
       }
       else if(mid*mid < N){
           ans = mid;
           s = mid + 1;
       }
       else{
           e = mid - 1;
       }
   }

   // Apply linera search inorder to get the accurate precision value
   
   float inc = 0.1;
   for(int place=1;place<=P;place++){

       // Linear Search
       while(ans*ans <= N){
           ans+=inc;
       }
       ans = ans - inc;
       inc = inc/10.0;
   }

   return ans;
}

int main(){
    
    int n=10,p=3;
    cout<<square_root(n,p);
    return 0;
}