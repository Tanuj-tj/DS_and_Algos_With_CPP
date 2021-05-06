#include <iostream>
using namespace std;

/* IsSafe function will check if a queen (1) can be placed at the perticular location or not  
  by checking all the possible attacks of in the current row,cols and diagonals*/


bool isSafe(int** arr,int x,int y,int n){

    /* Here, **arr is a dynamic array
              x and y are rows and columns 
              n is the no. of rows and columns  */

    // Here we are checking if any queen is present in a column or not 
   for(int row=0;row<x;row++){
       if(arr[row][y]==1){
           return false;
       }

   } 

   // Checking for diagonals

   /* we are performing (row-- , col--) for the upper left diagonal and 
                        (row-- , col++) for the upper right diagonal  */

   // Left Diagonal

   int row=x;
   int col=y;

   while(row>=0 && col>=0){
       if(arr[row][col]==1){
           return false;
       }
       row--;
       col--;
   }

   // Right Diagonal

   row=x;
   col=y;

   while(row>=0 && col<n){
       if(arr[row][col]==1){
           return false;
       }
       row--;
       col++;
   }

   return true;
}

/* Main N Queen function  */

bool nQueen(int** arr,int x,int n){

    // Base condition
    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQueen(arr,x+1,n)){
                return true;
            }

            arr[x][col]=0;  // Backtracking
        }
    
    }

    return false;
}


int main(){

    int n;
    cin>>n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;i<n;j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }

}