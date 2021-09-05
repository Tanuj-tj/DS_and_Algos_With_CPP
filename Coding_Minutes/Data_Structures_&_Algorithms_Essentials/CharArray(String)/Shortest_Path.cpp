#include<bits/stdc++.h>
using namespace std;

/*
Find Displacement : Given a long route containing,N,S,E,W direction, 
find the shortes path to reach the location

Sample I/P :
SNNNEWE

Sample O/P :
NNE

*/

int main(){

	char route[1000];
	cin.getline(route,1000);

	int x = 0 , y = 0;

	for(int i = 0 ; route[i] != '\0' ; i++ ){

		switch(route[i]){
			case 'N' : y++;
			break;

			case 'S' : y--;
			break;

			case 'E' : x++;
			break;

			case 'W' : x--;
			break;

		}
	} 

	cout<<"Coordinated of x and y are : "<<x<<","<<y<<endl;

    // Get the shortest path

    string shortest_path = "";

	if(x >= 0 and y >= 0){
		while(y--){
			shortest_path += 'N';
		}
		while(x--){
			shortest_path += 'E';
		}
	}	
	else{
		while(y++){
			shortest_path += 'S';
		}
		while(x++){
			shortest_path += 'W';
		}
	}

	cout<<"Shortest path : "<<shortest_path<<endl;


	return 0;
}
