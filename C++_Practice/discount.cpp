#include<iostream>
using namespace std;

int main(){
    
    cout<<"Enter total amount: "<<endl;
    float total_amount; cin>>total_amount;
    float discount =0.0;
  
    if(total_amount < 100){
        cout<<"No discount"<<endl;
    }
    else if ((total_amount >= 100) and (total_amount < 500 )){
        cout<<total_amount-(total_amount * 0.1);  
    }
    else{
        cout<<total_amount-(total_amount * 0.2); 
    }
    
    return 0;
}