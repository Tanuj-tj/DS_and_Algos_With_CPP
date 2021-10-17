/*
Approach : O(120 * N)

The idea is to use Hashing.
Instead of processing all 20000 people, we can process pairs of (age, count) representing how many people are there of that age.
According to the Constraints, since there are only 120 possible ages this means that there can be a Maximum of 120 pairs. Processing 120 elements is much faster than processing 20000 elements.
For each pair (ageA, countA) and (ageB, countB), if the conditions are satisfied with respect to age, then countA * countB
pairs of people made friend requests.
If (ageA = ageB), then we over counted and we should have countA * (countA - 1) pairs of people making friend requests
instead, as you cannot friend request yourself.

*/


#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main()
{
  //write your code here
  ll n;cin>>n;
  ll arr[n];
  for(ll i = 0 ; i < n ; i++) cin>>arr[i];
  
  unordered_map<int,int> mp;
  
  for(int i = 0 ; i < n ; i++){
    mp[arr[i]]++;
  }

  ll count = 0;
  
  for(auto i : mp){
    for(auto j : mp){

      if(j.first <= 0.5 * i.first + 7) continue;
      else if(j.first > 100 and i.first < 100) continue;
      else if(j.first > i.first) continue; 
      
      if(i==j) count += i.second * (i.second - 1);
      else count += i.second * j.second;
    }
  }
  
  cout<<count<<endl;
  
  return 0;
}
