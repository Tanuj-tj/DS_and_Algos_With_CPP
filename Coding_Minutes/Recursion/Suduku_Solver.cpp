/*
Sudoku Solve
============

Given a partially filled Sudoku Matrix of 9 X 9,
write a function to fill the matrix using Sudoku Rules.

Input :
2D Matrix

Output :
Solved 2D Matrix

*/


#include<bits/stdc++.h>
using namespace std;


// Check if the no. can be filled in the current block or not
bool isSafe(int grid[][9], int i,int j, int no){
  
   // Check if the element is preset in the current row and column
   for(int k=0;k<9;k++){
       if(grid[k][j]==no || grid[i][k]==no){
           return false;
       }
   }

   // Check if the element is preset in the current grid
   int sx = (i/3)*3;
   int sy = (j/3)*3;

   for(int x=sx;x<sx+3;x++){
       for(int y=sy;y<sy+3;y++){
           if(grid[x][y]==no){
               return false;
           }
       }
   }

   return true;

}

bool solveSuduko(int grid[][9],int i, int j, int n ) {
    
    // Base case i = n // True, 
    // We are at the end of our suduku grid so we can retrun true    
     if(i==n){
         for(int x=0;x<9;x++){
             for(int y=0;y<9;y++){
                 cout<<grid[x][y]<<" ";
             }
             cout<<endl;
         }
         return true;
     }

    //Recursive case

    //move downwords if the current row is solved
    if(j==n){
        return solveSuduko(grid,i+1,0,n);
    }
   
    // Skip the block if the block is already filled
    if(grid[i][j]!=0){
        return solveSuduko(grid,i,j+1,n);
    }

    // fill the empty block or the block containg zeros

    // Nos to be filled can be in between 1 to 9
    for(int no=1;no<=n;no++){
        // check if the ith element can be inserted or not
        if(isSafe(grid,i,j,no)){
            grid[i][j] = no;
            bool solveSubproblem = solveSuduko(grid,i,j+1,n);
            if(solveSubproblem == true){
                return true;
            }
        }
    }

    // Backtracking step if the current block cannot be filled with any no.
    grid[i][j] = 0;
    return false;
}

int main(){
     
    int N = 9;
    int grid[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 
    if (!solveSuduko(grid,0,0,N)){
        cout << "no solution  exists " << endl;
    }
    return 0;
}