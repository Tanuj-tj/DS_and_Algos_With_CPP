#include<bits/stdc++.h>
using namespace std;

vector<int> next_greatest_to_Right(vector<int> v1){
    vector<int> v;       
    stack<int> s;

    for(int i=v1.size()-1;i>=0;i--){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() > v1[i]){         
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= v1[i]){       // 3 <= 3
            while(s.size() > 0 && s.top() <= v1[i]){     // 
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(v1[i]);
    }

    reverse(v.begin(),v.end());

    return v;

}

vector<int> next_greatest_to_Left(vector<int> arr){  // arr = {1,3,2,4}
    vector<int> v;  //  -1 , 
    stack<int> s;   //   1 , 
 
    for(int i=0;i<arr.size();i++){

        if(s.size() == 0){                                     
            v.push_back(-1);
        }
        else if(s.size() > 0 && s.top() > arr[i]){
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= arr[i]){
             while(s.size() > 0 && s.top() <= arr[i]){
                 s.pop();
             }
             if(s.size()==0){
                 v.push_back(-1);
             }
             else{
                 v.push_back(s.top());
             }
        }


        s.push(arr[i]);
    }

    return v;
}



int main(){
    vector<int> v1 = {1,3,2,4}; // [-1] = False
  
    cout<<"Input Array: ";
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    cout<<"Next Greatest To Right: ";
    for(int i=0;i<v1.size();i++){
        cout<<next_greatest_to_Right(v1)[i]<<" ";
    }
    cout<<endl;

    cout<<"Next Greatest To Left: ";
    for(int i=0;i<v1.size();i++){
        cout<<next_greatest_to_Left(v1)[i]<<" ";
    }

    return 0;
}
