/*
Readlng Books
=============

Given number of pages in n different books and m students The bools are arranged in any
order (not necessarily ascending) of number of pages. Every student is assigned to read some
consecutive segment of books. The task is to assign books in such a way that the maximum
number of pages assigned to a student is minimum.

Find the maximum number of pages that a student will have to read.

Sample Input :

books = [10, 20,30,15]
students = 2

Sample Output :
45

Solution Link : https://www.geeksforgeeks.org/allocate-minimum-number-pages/

Approach :
1. Recurion => partitioning the given array  [10 | 20 30 15] or [10 20  | 30 15]
   -> Complexity : O(2^N)

2. Dynamic Programming 
   -> Complexity : O(N^2)

3. Binary Search => Think about a search space  
   -> Complexity : O(NLogN) 
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 1e18
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>
#define all(n) n.begin(),n.end()
#define mid(l,r) (l+(r-l)/2)
#define F first
#define S second
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;


bool isValid(vi &books,int m,int mid){

    int students = 1;
    int sum = 0;

    for(int i=0;i<books.size();i++){
        if(sum + books[i] > mid){
            students++;
            sum = books[i];
        }else{
            sum += books[i];
        }
    }

    return students <= m;

}

int minPages(vector<int> &books, int students){
    
    int s = *max_element(all(books));    // Min =>  eq. if only one student is preset
    int e = accumulate(all(books), 0);    // Max => eg. if n students are present

    int res = 0;

    while(s<=e){
        int mid = mid(s,e); 
        if(isValid(books,students,mid)){
            e = mid - 1;
            res = mid;
        } 
        else{
            s = mid + 1;
        }
    }

    return res;
}

int main(){
   
    vi books{12, 34, 67, 90};   // 113
    int students = 2;

    cout<<minPages(books,students)<<endl;
	return 0;
}