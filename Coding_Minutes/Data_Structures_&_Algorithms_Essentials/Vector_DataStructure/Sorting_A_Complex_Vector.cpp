/* Sort on the basic of total marks of students */

#include<bits/stdc++.h>
using namespace std;

int calculateTotalMarks(vector<int> m){
	int total = 0;
	for(int i = 0 ; i < m.size() ; i ++){
		total += m[i];
	}
	return total;
}

bool compare(pair<string,vector<int>> s1, pair<string,vector<int>> s2){
	
	return calculateTotalMarks(s1.second) > calculateTotalMarks(s2.second);
}

int main(){

	vector<pair<string,vector<int>>> student_marks = {
		{"Rohan", {10,20,11}},
		{"Prateek",{10,21,3}},
		{"Vivek",{4,5,6}},
		{"Rijul",{10,13,20}}
	};

	sort(student_marks.begin(),student_marks.end(),compare);

	for(auto s : student_marks){
		cout<<s.first<<" "<<calculateTotalMarks(s.second)<<endl;
	}

	return 0;
}