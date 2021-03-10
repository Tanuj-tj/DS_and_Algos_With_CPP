#include<iostream>
using namespace std;

int main(){
     
    cout<<"Enter a no."<<endl; 
    int num; cin>>num;
    int temp = num;
    int rev = 0;
    int iter = 1;

    while(temp!=0){

        int last = temp%10;

        cout<<"Iteration: "<<iter<<endl;
        cout<<"Last digit: "<<last<<endl;

        rev = (rev * 10) + last;

        cout<<"Rev: "<<rev<<endl;

        temp = temp / 10;

        cout<<"Temp: "<<temp<<endl;

        iter++; 
    }

    if(rev == num)
        cout<<"Palindrome"<<endl;
    else    
        cout<<"Not a palindrome"<<endl;

    return 0;
}