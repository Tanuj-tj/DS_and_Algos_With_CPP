#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

string extractStringAtKey(string str,int key){

    // String tokenizer
    char *s = strtok( (char *)str.c_str(), " ");
    while(key>1){
        s = strtok(NULL," ");
        key--;
    }
    return (string)s;
}
 
bool lexicoCompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1 = s1.second;
    key2 = s2.second;

    return key1 < key2;
}


/*

 Method to convert string to int manually :

int converToInt(string s){
    
    int ans = 0;
    int p = 1;

    for(int i=s.length()-1; i>=0; i--){
        ans+= ((s[i]-'0')*p);
        p = p*10;
    }
    return ans;
}

*/

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
    string key1,key2;
    key1 = s1.second;
    key2 = s2.second;

    // stoi method is a inbuilt method to convert string to int

    return stoi(key1) < stoi(key2);
}

int main(){

    // string s = "92 022";
    // cout<<extractStringAtKey(s,2)<<endl;

    int n;cin>>n;
     
     // Next line 
     cin.get(); // Consume the extra \n

     string temp;
     vector<string> v;

     for(int i=0;i<n;i++){
     	getline(cin,temp);
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;
    
   
    // Steps :
     
    // 1. To extract key for the comparision and store them 

     vector<pair<string,string>> vp;
     for(int i=0;i<n;i++){
         vp.push_back({v[i], extractStringAtKey(v[i],key)});

         //cout<<vp[i].first<<" "<<vp[i].second<<endl;

     }

     /*
      o/p for the above vector vp :

        92 022 022
        82 12 12
        77 13 13

     */

    // 2. Sorting

    if(ordering == "numeric"){
        sort(vp.begin(),vp.end(),numericCompare);
    }
    else{
        sort(vp.begin(),vp.end(),lexicoCompare);
    }

    // 3. Reversal

    if(reversal == "true"){
        reverse(vp.begin(),vp.end());
    }

    // 4. Output

    for(int i=0;i<n;i++){
        cout<< vp[i].first << endl;
    }

         
	return 0;
}


/*

Test Case :

I/P =>

3
92 022
82 12
77 13
2 false numeric

O/P =>

82 12
77 13
92 022

*/