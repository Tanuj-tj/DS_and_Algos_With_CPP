/*
Given a vector of pairs representing coordinated x and y of
different cabs on a X-Y plane. Sort them according to
their distance from the origin in the non-decreasing order 

input : {(2,3),(1,2),(3,4),(2,4),(1,4)}
output : {(1,2),(2,3),(1,4),(2,4),(3,4)}
*/

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){

    // Euclidian Distance : √{(x-0)2 + (y-0)2}

	int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second; 

	float d1 = sqrt( (x1*x1) + (y1*y1));
	float d2 = sqrt( (x2*x2) + (y2*y2));

	return d1 < d2;
}

vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){
    
    vector<pair<int,int>> v1 = v;
    sort(v1.begin(),v1.end(),comp);
    return v1;
    
}

int main(){
	vector<pair<int,int>> v {{2,3},{1,2},{3,4},{2,4},{1,4}};
	auto ans = sortCabs(v);
	for(auto i : ans){
		cout<<i.first<<" "<<i.second<<endl;
	}
}