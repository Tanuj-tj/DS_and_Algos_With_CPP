// Reverse a stack

// I/P : 1 2 3 4 5
// O/P : 5 4 3 2 1

#include <iostream>
#include <stack>  // Included with c++ STL

using namespace std;

void insertAtBottom(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topelement = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topelement);

}

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}

int main()
{
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   reverse(st);
   while(!st.empty()){
       cout<<st.top()<<endl;
       st.pop();
   }
   cout<<endl;
   return 0;
}
