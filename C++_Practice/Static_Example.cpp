#include<iostream>
using namespace std;

class Student{
   
   private:
   int roll;
   string name;
   
   public:
   static int addNo;
   Student(string n){
       name=n;
       roll=addNo;
       addNo++;
   }
   void display(){
       cout<<"Name: "<<name<<"Roll No: "<<roll<<endl;
   }

};

int Student::addNo=0;

int main(){

    Student s1("John");
    Student s2("Ravi");
    Student s3("Khan");
    Student s4("Ram");

    s1.display();
    s2.display();
    s3.display();
    s4.display();
    
    cout<<"Total Admissions: "<<Student::addNo<<endl;

    return 0;
}