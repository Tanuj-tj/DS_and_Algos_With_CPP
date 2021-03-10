#include<iostream>
using namespace std;

class Student{

    private:
    int roll;
    string name;
    int math_marks , physics_marks, chem_marks;

    public:

    Student(int r,string n,int mat_m,int phy_m,int chem_m){
        roll = r;
        name = n;
        math_marks = mat_m;
        physics_marks = phy_m; 
        chem_marks=chem_m;
    }

    int total_marks(){
        return math_marks+physics_marks+chem_marks;
    }

    string grade(){

        int avg = total_marks() / 3; 
        if(avg > 60){
            return "A";
        }
        else if(avg>=40 && avg<=60){
            return "B";
        }
        else{
            return "C";
        }
    }


};

int main(){
    cout<<"Enter roll no."<<endl;
    int roll;cin>>roll;
    cout<<"Enter Name"<<endl;
    string name;cin>>name;
    cout<<"Enter Maths Marks"<<endl;
    int math_m;cin>>math_m;
    cout<<"Enter Physics Marks"<<endl;
    int phy_m;cin>>phy_m;
    cout<<"Enter Chemistry Marks"<<endl;
    int chem_m;cin>>chem_m;
    
    Student s1(roll,name,math_m,phy_m,chem_m);
    cout<<"Total: "<<s1.total_marks();
    cout<<endl;
    cout<<"Grades: "<<s1.grade()<<endl;

    return 0;
}