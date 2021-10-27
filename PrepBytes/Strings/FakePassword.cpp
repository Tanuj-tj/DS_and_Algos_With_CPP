#include <bits/stdc++.h>
using namespace std;

void leftrotate(string &s)
{
    int d = 2;
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

void rightrotate(string &s)
{ 
   int d = s.length()-2;
   reverse(s.begin(), s.begin()+d);
   reverse(s.begin()+d, s.end());
   reverse(s.begin(), s.end());
}

int main()
{
  //write your code here
  int t; cin>>t;
  while(t--){
    string o; cin>>o;
    string f; cin>>f;
    
    string fr = f,fl = f;
    
    rightrotate(fr);
    leftrotate(fl);
    
    if(o==fr or o==fl) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

  }
  return 0;
}
