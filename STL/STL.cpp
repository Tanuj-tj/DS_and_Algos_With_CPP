
// Headers files
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool fun(int x,int y){
    return x > y;
}

void vectorDemo(){
    
    /* Defination :
    ---------------
    Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
    with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that
    they can be accessed and traversed using iterators. In vectors, data is inserted at the end. 
    Inserting at the end takes differential time, as sometimes there may be a need of extending the array. 
    Removing the last element takes only constant time because no resizing happens. Inserting and erasing
    at the beginning or in the middle is linear in time.*/
    
    vector<int> A = {11,2,3,14} ;
    cout<<A[1]<<endl;  // O/P : 2
   
    /*** Sorting ***/
    
    sort(A.begin(), A.end()); // Complexity : O(NlogN)
                              // O/P : 2,3,11,14   

    /*** Binary Search ***/
    
    // I/P : 2,3,11,14   
    // Complexity : O(logN)
    
    bool present = binary_search(A.begin(),A.end(),3);  // O/P : True
    present = binary_search(A.begin(),A.end(),4);  // O/P : False
    
    /*** Insert new elements at the back ***/
    
    A.push_back(100);  // O/P : 2,3,11,14,100
    
    present = binary_search(A.begin(),A.end(),100); // O/P : True
    
    /*** Checking the first occurance of a number ***/
    
    // Inserting 100 some more times
     A.push_back(100);  // O/P : 2,3,11,14,100,100
     A.push_back(100);  // O/P : 2,3,11,14,100,100,100
     A.push_back(100);  // O/P : 2,3,11,14,100,100,100,100
     A.push_back(100);  // O/P : 2,3,11,14,100,100,100,100,100
     A.push_back(123);  // O/P : 2,3,11,14,100,100,100,100,100,123
     
     
     /*** ABOUT ITERATORS ***/
     
     /* An iterator is an object (like a pointer) that points to an element inside the container. 
      We can use iterators to move through the contents of the container. 
      They can be visualized as something similar to a pointer pointing to some location and 
      we can access the content at that particular location using them. */
     
     // lower_bound will return the first occurance of the passed integer (>=)
     vector<int>::iterator it1 = lower_bound(A.begin(),A.end(),100); // O/P : 4
     
     // upper_bound will return the last occurance of the passed integer (>)
     vector<int>::iterator it2 = upper_bound(A.begin(),A.end(),100); // O/p : 8
     
    // Arthmetic operations on iterators
    
    cout<<*it1<<" "<<*it2<<endl;  // O/P : 100 100
    cout<<it2 - it1 <<endl;   // O/P : 5 
    
    /*** Reverse Sort ***/
    sort(A.begin(), A.end() , fun);
    
    vector<int>::iterator it3;
    
    cout<<"Reverse: "<<endl;
    for(it3 = A.begin(); it3 != A.end(); it3++){
        cout<<*it3<<" ";
    }
    cout<<endl;
    
    /*Using auto insted of iterator*/
    
     auto it4 = lower_bound(A.begin(),A.end(),100); // O/P : 4
     
     auto it5 = upper_bound(A.begin(),A.end(),100); // O/p : 8
     
    // Arthmetic operations on iterators
    
    cout<<*it4<<" "<<*it4<<endl;  // O/P : 100 100
    cout<<it5 - it4 <<endl;   // O/P : 5 
    
    /*** Reverse Sort ***/
    sort(A.begin(), A.end() , fun);
    
    cout<<"Print using auto: "<<endl;
    for(int x : A){
        cout<<x<<" ";
    }
    cout<<endl;
    
}

void setDemo(){
    
    /* Defination :
    ---------------
    Sets are a type of associative containers in which each element has to be unique, 
    because the value of the element identifies it. The value of the element cannot be 
    modified once it is added to the set, though it is possible to remove and add the 
    modified value of that element.*/
    
    /* Creating a set */
    set<int> s;
    
    /* Inserting elements in a set */
     // Set By default maintains the assending order of elements
    s.insert(1);
    s.insert(2);      // Each operation is performed in O(logN) times
    s.insert(-1);
    s.insert(-10);
     
    for(int x : s){
        cout<<x<<" ";
    }
    cout<<endl;           // O/P : --10,-1,1,2
    
    // Check if a element is present in a set or not
    auto it = s.find(-1);
    if(it == s.end()){
        cout<<"not present"<<endl;
    }
    else{
        cout<<"Present"<<endl;
        cout<<*it<<endl;
    }
    
    auto it2 = s.lower_bound(-1);
    auto it3 = s.upper_bound(0);
    
    cout<<*it2<<" "<<*it3<<endl;
    
    auto it4 = s.upper_bound(2);
    if(it4 == s.end()){
        cout<<"Element not found!!!!"<<endl;
    }
    
    // Erase any element
    
    s.erase(1);
    for(int x : s){
        cout<<x<<" ";
    }
    cout<<endl;     // O/P : -10 -1 2
}

void mapDemo(){
    
    /*Defination :
    -------------
    Maps are associative containers that store elements in a mapped fashion. 
    Each element has a key value and a mapped value. 
    No two mapped values can have same key values.*/
    
    map<int, int> B;
    B[1] = 100;
    B[2] = -1;
    B[3] = 200;
    B[100000232] = 1;
    
    map<char,int> cnt;
    string x = "Tanuj shrivastava";
    
    for(char c : x){
        cnt[c]++;
    }
    
    cout<<cnt['a']<<" "<<cnt['z']<<endl;
}

void powerOfSTL(){
    
    set<pair<int,int>> s;
    
    s.inset({401,450});
    s.inset({10,20});
    s.inset({2,3});
    s.inset({30,400});
    
    // The set will first arange the pairs internally in Ascending order and the 
    // arrange them in set again in ascending order 
    
    /* O/P:
    
    2,3
    10,20
    30,400
    401,450
    
    */
    
    
    
}


int main()
{
    //vectorDemo();
    //setDemo();
    //mapDemo();
    powerOfSTL();
    
   
    return 0;
}