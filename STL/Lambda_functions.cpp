#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Lambda functions
    cout<<[](int x,int y){return x+y;}(2,4)<<endl;
    
    // Assigning lambda functions
    auto sum = [](int x,int y){return x+y;};
    cout<<sum(2,3)<<endl;
    
    vector<int> v = {2,3,5};
    
    // all_of function
    cout<<all_of(v.begin(),v.end(), [](int x){return x > 0;})<<endl;
    
    // any_of
    cout<<any_of(v.begin(),v.end(), [](int x){return x > 0;})<<endl;
    
    // none_of
    cout<<none_of(v.begin(),v.end(), [](int x){return x > 0;})<<endl;    

    return 0;
}
