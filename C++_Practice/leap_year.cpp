#include<iostream>
using namespace std;

int main(){
    
    cout<<"Enter a year: "<<endl;
    int year; cin>>year;

    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0)
                cout<<"Lear Year!!!"<<endl;
            else    
                cout<<"Not a leap year"<<endl;
        }
        else{
            cout<<"Leap Year"<<endl;
        }
    }
    else
        cout<<"Not a leap leap year"<<endl;
    
    return 0;
}