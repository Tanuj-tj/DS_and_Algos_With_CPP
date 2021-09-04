#include<bits/stdc++.h>
#define vi vector<int>
#define vp vector<pair<int,int>>
using namespace std;

void defkin(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here

    vector<int> p1;
    p1.push_back(0);
    for(auto i : position) p1.push_back(i.first);
 	p1.push_back(W+1);
  	sort(p1.begin(),p1.end());

    vector<int> p2;
	p2.push_back(0);
	for(auto i : position) p2.push_back(i.second);
	p2.push_back(H+1);
	sort(p2.begin(),p2.end());

    int mx = 0, my = 0;
	for(int i = 0 ; i < p1.size()-1 ; i++){
		mx = max(mx, p1[i+1] - p1[i] - 1);
		my = max(my, p2[i+1] - p2[i] - 1); 
	}

	cout<<mx * my<<endl;

}

int main(){

	int W = 15, H = 8;
	vector<pair<int, int>> position{{3,8},{11,2},{8,6}};
	defkin(W,H,position);

	return 0;
}
