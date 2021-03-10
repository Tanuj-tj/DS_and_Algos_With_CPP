#include<iostream>
using namespace std;

class Employee{
   private:
   int eid;
   string name;
   public:
   Employee(int eid,string name){
       this->eid = eid;
       this->name = name;
   }
   int getId(){return eid;}
   string getName(){return name;}
};
class FullTime_Emp:public Employee{
    int salary;
    public:
    FullTime_Emp(int eid,string name, int salary):Employee(eid,name){
        this->salary = salary;
    }
    int getSalary(){return salary;}
};

class PartTime_Emp:public Employee{
    int Wages;
    public:
    PartTime_Emp(int eid,string name,int Wages):Employee(eid,name){
        this->Wages = Wages;
    }
    int getWages(){return Wages;}

};

int main(){

    FullTime_Emp f(101,"abc",1200);
    PartTime_Emp p(102,"xyz",120);

    cout<<"Name: "<<f.getName()<<" Salary: "<<f.getSalary()<<endl; 
    cout<<"Name: "<<p.getName()<<" Salary: "<<p.getWages()<<endl; 

    return 0;
}