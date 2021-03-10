#include<iostream>
using namespace std;

class Rational{
    private:
    int num;
    int den;

    public:
    Rational(int num=1,int den=1){
        this->num = num;
        this->den = den;
    }
    Rational operator+(Rational r){
        Rational t;
        t.num = this->num * r.den + this->den * r.num;
        t.den = this->den * r.den;
        return t;
    }
    friend ostream & operator<<(ostream &out,Rational &c);
};
    ostream & operator<<(ostream &out,Rational &c){
        out<<c.num<<"/"<<c.den<<endl;
        return out; 
    }

int main(){

    Rational R1(3,4),R2(2,5),res;
    res = R1 + R2;
    Rational 
    cout<<res<<endl;
    

    return 0;
}