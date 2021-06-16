#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i = 10; i>=0;--i){
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

int main(){
   
    int n = 5;
    printBinary(n);

    // Odd Even No.
    
    if(n&1){
        cout<<"Odd"<<endl;
    } 
    else{
        cout<<"Even"<<endl;
    }

    // Muliply and Divide by 2
    
    cout << (n>>1) << endl;  //  /2
    cout << (n<<1) << endl;  //  *2

    // Upper and lower case

    char a = 'a';

    cout<<char(a & (~(1<<5)))<<endl;  // A
    cout<<char(a & '_')<<endl;  // A

    char A = 'A';

    cout<<char(A | (1<<5))<<endl;  // a
    cout<<char(A | ' ')<<endl;

    // Clear Least Significient Bits
    
    printBinary(59);
    int x = 59;
    int i = 4;
    int b = (x & (~((1<<(i+1)) - 1)));
    printBinary(b);

    // Clear Most Significient Bits
    i = 3;
    int c = (x & ((1<<(i+1))-1 ));
    printBinary(c);

    // Check power of 2

    int check = 16;
    
    if(check&(check-1)){
        cout<<"Not a Power of 2"<<endl;
    }
    else{
        cout<<" power of 2"<<endl;
    }

    return 0;
}
