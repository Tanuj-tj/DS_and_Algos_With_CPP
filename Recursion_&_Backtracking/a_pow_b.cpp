#include<iostream>
using namespace std;

int pow(int a,int b){
    if(b==0)
        return 1;

    return pow(a,b-1) * a;
}

/*       pow(2,2) 
            |
         pow(2,1) * 2  // 2 * 2 = 4  
            |
         pow(2,0) * 2  // 1 * 2 = 2
            |
          b=0 => cond. false

*/

int main(){

    int a = 2,b=2;
    cout<<pow(a,b)<<endl;
}