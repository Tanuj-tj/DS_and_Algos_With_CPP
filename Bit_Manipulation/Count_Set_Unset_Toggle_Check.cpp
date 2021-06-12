#include <iostream>

using namespace std;

// Bits

void printBinary(int num){
    for(int i = 10; i>=0;--i){
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

int main()
{
    int x = 5;  // 101
    printBinary(x);
    int i = 0;
    
    // check if the bit is set bit or not
    if(x & (1 >> i )){
        cout<<"Set bit"<<endl;
    }
    else{
        cout<<"Unset Bit"<<endl;
    }
    
    // set Bit
    printBinary( x | (1 << i) );
    
    // Unset Bit
    printBinary( x & (~(1 << i)) );
    
    // Toggle
    printBinary( x ^ (1 << i) );
    
    // count
    cout<< __builtin_popcount(x)<<endl;
    return 0;
}
