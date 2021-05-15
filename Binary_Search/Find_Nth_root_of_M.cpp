#include<bits/stdc++.h>
using namespace std;

double eps = 1e-1;

double multiply(double mid,int n){
    double ans=1;
    for(int i=0;i<n;i++){
        ans*=mid;
    }
    return ans;
}
    
double NthRoot(int n, double m)  // n = 2 , m = 9
{
	  double low = 0;  // 0
	  double high = m;  // 9
	   double mid;
	   
	   while(high-low > eps){
	       
	       mid = (low + high)/2;
	       
	       if(multiply(mid,n) <  m){
	           low = mid;
	       }
	       else{
	           high = mid;
	       }
	   }
	   return high;  
}

int main(){
    
    int n = 3;
    double m = 9;
    cout<<NthRoot(n, m)<<endl;
    
    return 0;
}
