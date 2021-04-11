#include <iostream>

using namespace std;

void fun1(int n){
    if(n>0){
        cout<<n<<endl;  // 3 , fun(2) |  2 , fun(1) | 1 , if condition false 
        fun1(n-1);
    }
}

/*

    fun(3)
     / \
    3  fun(2)
       / \
      2  fun(1)
          / \
         1  fun(0)
            Conditon false
*/

void fun2(int n){
    
    if(n>0){
        fun2(n-1);
        cout<<n<<endl;
    }
}

/*
        fun2(3) 
          / \
    fun2(2)  3 
       /  \
  fun2(1)  2
     /  \
fun2(0)  1
   /  
False  

*/



int main()
{
    int x = 3;
    fun1(x);
    cout<<endl;
    fun2(x);

    return 0;
}