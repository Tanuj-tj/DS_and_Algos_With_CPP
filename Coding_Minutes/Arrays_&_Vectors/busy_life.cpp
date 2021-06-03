/*
Busy Llfe

You are actually very busy person. You have a long list of activities. Your aim is to finish much as
activities as possible.

In the given figure, if you go to date with crush, you cannot participate in the coding contest and
you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for
the exam you can't sleep peacefully. The maximum number of activities that you can do for this
schedule is 3.

Either you can
* watch movie, play DotA and sleep peacefully (or)
* date with crush, play DotA and sleep peacefully

Given the start and finish times of activities, print the maximum number of activities. Input is
already store in a vector of pairs. Each pair contains the start and end of the activity.

Sample Input :

(7,9) (0,10) (4,5) (8,9) (4,10) (5,7)

Output :

3

*/

/*
Approach :

The greedy choice is to always pick the next activity whose finish time is least among the remaining activities and 
the start time is more than or equal to the finish time of the previously selected activity. We can sort the activities 
according to their finishing time so that we always consider the next activity as minimum finishing time activity.

1.) Initialize a variable ans = 0;
2.) Sort the activities according to their finishing time.
3.) Select the first activity from the sorted array and increment ans.
4.) Do the following for the remaining activities in the sorted array.
   a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity then 
   select this activity and increment ans.

5.) return ans.

*/

#include<bits/stdc++.h>
using namespace std;

// Comparator function to sort according the finished time
bool compare(const pair<int, int>&i, const pair<int, int>&j) { 
    return i.second < j.second; 
}

int countActivites(vector<pair<int,int> > &activities){

    // Array size
    int n = activities.size();

    // Sort the activities w.r.t finish time
    sort(activities.begin(), activities.end(),compare);  // O(NLogN)  
         
        // { {4,5}, {5, 7}, {7, 9}, {8,9},{0,10}, {4,10}} 

    int ans = 0;  // 1 ,2 , 3
    int prev = 0;

    for(int i=0;i<n;i++){  // i = 0 , 1 , 2 , 3 , 4, 5 
        
        if(i==0){
            ans++;  // 1 , 
        }
        else if(activities[i].first >= activities[prev].second ){
            ans++;  // 2
            prev = i;
        } 

    }    
    
    return ans;
    
}

int main(){
     
    vector<pair<int,int> > activities = {{7,9}, {0,10}, {4,5}, {8,9}, {4,10}, {5,7}};

    cout<<countActivites(activities)<<endl;

    return 0;
}