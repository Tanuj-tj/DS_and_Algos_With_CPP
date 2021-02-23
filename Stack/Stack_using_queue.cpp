/* Two Methods to perform this operation : 
   1. Making Push Operation costly
   2. Making Pop operation costly
 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Making_pop_costly{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Making_pop_costly(){
        N = 0;
    }

    void pop(){

        // Check if the q1 has some element to pop or not 
        if(q1.empty()){
            return;
        }

        // One by one pop the elements from q1 (until q1 has left with 1 element) and push them to q2 
        // Then pop the last element from q1 and decrese the size of N with every pop
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;

        // Swap the names of q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

    }

    void push(int val){
        q1.push(val);
        N++;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);

        // Swap the names of q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }
    int size(){
        return N;
    }
};


int main(){

    Making_pop_costly m1;
    m1.push(1);
    m1.push(2);
    m1.push(3);
    m1.push(4);
    cout<<"size of N: "<<m1.size()<<endl;
    cout<<"Top: "<<m1.top()<<endl;
    m1.pop();
    cout<<"Top: "<<m1.top()<<endl;
    m1.pop();
    cout<<"Top: "<<m1.size()<<endl;
    
}