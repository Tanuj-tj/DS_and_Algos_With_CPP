#include <iostream>
using namespace std;

#define N 5

bool isSafe(int maze[N][N],int row,int col){
    return maze[row][col]==1 && row<=N && col<=N;
}

int rat_in_maze(int maze[N][N],int row,int col,int sol[N][N]){
   
    // Base Condition
    if((row==N-1) && (col==N-1)){
        sol[row][col] = 1;
        return true;
    }

    if(isSafe(maze,row,col)){
        sol[row][col] = 1;
        if(rat_in_maze(maze,row+1,col,sol))
            return true;
        if(rat_in_maze(maze,row,col+1,sol))
            return true;
        sol[row][col]=0;
        return false;
    }
    return false;

}

int print_maze(int maze[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){ 

    int maze[N][N] = {{1,0,1,0,1},
                      {1,1,1,1,1},
                      {0,1,0,1,0},
                      {1,0,0,1,1},
                      {1,1,1,0,1}};

    int sol[N][N] = {{0,0,0,0,0},
                     {0,0,0,0,0},
                     {0,0,0,0,0},
                     {0,0,0,0,0},
                     {0,0,0,0,0}};


    cout<<"Given Maze"<<endl;
    print_maze(maze); 

    cout<<"Solved Maze"<<endl;
    if(rat_in_maze(maze,0,0,sol)){
        print_maze(sol);
    }

    return 0;
}