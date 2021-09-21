#include <bits/stdc++.h>
using namespace std;

string spell[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void rev(int n){
    if(n == 0) return;
    int lst = n % 10;
    rev(n/10);
    cout<<spell[lst]<<" ";
}

int main(){
    int n = 510;
    rev(n);
}
