/*
Defense Kingdom : https://www.spoj.com/problems/DEFKIN/

heodore implements a new strategy game “Defense of a Kingdom”. 
On each level a player defends the Kingdom that is represented by a rectangular grid of cells. 
The player builds crossbow towers in some cells of the grid. 
The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. 
For example, the position shown on the picture has penalty 12.

Input
The first line of the input file contains the number of test cases.

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.

*/


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
