#include <iostream>
#include<vector>

using namespace std;

int main()
{
   vector <int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   
   cout<<"---FOR LOOP-----"<<endl;
   
   for(int i=0;i<v.size();i++){
       cout<<v[i]<<endl;
   }
   
   cout<<"---ITERATOR-----"<<endl;
   
   vector<int>::iterator it;
   for(it=v.begin();it!=v.end();it++){
       cout<<*it<<endl;
   }
   
   cout<<"---AUTO KEYWORD-----"<<endl;
   
   for(auto element:v){
       cout<<element<<endl;
   }
   
   return 0;
}