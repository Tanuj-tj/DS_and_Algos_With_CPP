#include <bits/stdc++.h>
  using namespace std;

  int main()
  {
    //write your code here
    int n;
    cin>>n;
    
    int a[n];
    set<int> st;
    
    for(int i=0;i<n;i++) cin>>a[i];
    
    int diff[100000],lastIndex[100000];
    memset(diff,-1,sizeof(diff));
    
    bool finalNumbers[100000];
    memset(finalNumbers,true,sizeof(finalNumbers));
    
    for(int i=0;i<n;i++)
    {
      if(st.find(a[i])==st.end())
      {
        lastIndex[a[i]]=i;
        st.insert(a[i]);
      }
      else {
        if(diff[a[i]]!=-1 && lastIndex[a[i]]+diff[a[i]]!=i){
           st.erase(a[i]);
           finalNumbers[a[i]]=false;
        }
        else {
          diff[a[i]] = i-lastIndex[a[i]];
          lastIndex[a[i]] = i;
        }
      }
    }
    int size = st.size();
    for(int num: st) if(finalNumbers[num]==false) size--;
    cout<<size<<endl;
    
    for(int num: st)
    {
      if(finalNumbers[num]){
      if(diff[num]==-1) diff[num]=0;
      cout<<num<<" "<<diff[num];
      cout<<endl;
      }
      
    }
    
    return 0;
  }
