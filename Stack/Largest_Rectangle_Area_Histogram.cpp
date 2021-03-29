// Index= 0  1  2  3  4  5  6  7 
// Arr = {6  2  5  4  5  1  6 MAX}
// NSR =  1  5  3  5  5  7  7
// NSL = -1 -1  1  1  3 -1  5

// Width[] = NSR - NSL - 1
// Area[] = Arr[i] * Width[i]
// max(Area[])

#include<bits/stdc++.h>
using namespace std;


vector<int> Next_Smallest_Left(vector<int> arr){
 	vector<int> left;
 	stack<pair<int,int>> s;  // {value , index}
    
    for(int i=0;i<arr.size();i++){
    	if(s.size() == 0){
    		left.push_back(-1);
    	}
    	else if(s.size() > 0 && s.top().first < arr[i]){
    		left.push_back(s.top().second);
    	}
    	else if(s.size() > 0 && s.top().first >= arr[i]){
    		while(s.size() > 0 && s.top().first >= arr[i]){
    			s.pop();
    		}
    		if(s.size()==0){
    			left.push_back(-1);
    		}
    		else{
    			left.push_back(s.top().second);
    		}
    	}
    	s.push({arr[i],i});  
    }

    return left;

}

vector<int> Next_Smallest_Right(vector<int> arr){
 	vector<int> right;
 	stack<pair<int,int>> s;  // {value , index}
    
    for(int i=arr.size();i>=0;i--){
    	if(s.size() == 0){
    		right.push_back(arr.size());
    	}
    	else if(s.size() > 0 && s.top().first < arr[i]){
    		right.push_back(s.top().second);
    	}
    	else if(s.size() > 0 && s.top().first >= arr[i]){
    		while(s.size() > 0 && s.top().first >= arr[i]){
    			s.pop();
    		}
    		if(s.size()==0){
    			right.push_back(7);
    		}
    		else{
    			right.push_back(s.top().second);
    		}
    	}
    	s.push({arr[i],i});  
    }

    reverse(right.begin(),right.end());

    return right;

}  

int main(){
    
    vector<int> arr = {6, 2, 5, 4, 5, 1, 6};
                  //  -1 -1  1  1  3  -1 5                  
    cout<<"Input : ";
    for(int i=0;i<arr.size();i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"NSL Indexes : ";
    for(int i=0;i<arr.size();i++){
    	cout<<Next_Smallest_Left(arr)[i]<<" ";
    }
    cout<<endl;

    cout<<"NSR Indexes : ";
    for(int i=0;i<arr.size();i++){
    	cout<<Next_Smallest_Right(arr)[i]<<" ";
    }
    cout<<endl;

    cout<<"Area : ";

    // NSL
	//Next_Smallest_Left(arr);
	
	// NSR
	//Next_Smallest_Right(arr);

    // Width[] = NSR - NSL - 1
      //int width[arr.size()];
     
     vector<int> width;
     for(int i=0;i<arr.size();i++){
        width.push_back(Next_Smallest_Right(arr)[i] - Next_Smallest_Left(arr)[i] - 1);
     //	cout<<width[i]<<" ";
      }


     // Area[] = Arr[i] * Width[i]
    vector<int> area;

    for(int i=0;i<arr.size();i++){
    	area.push_back(arr[i] * width[i]);
    	cout<<area[i]<<" ";

    }
    cout<<endl;

    cout<<"Maximum Area : ";

    vector<int>::iterator it;
    it = max_element(area.begin(), area.end());
    cout<<*it<<endl;

	return 0;
}