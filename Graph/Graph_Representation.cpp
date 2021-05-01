// Graph representations

#include <bits/stdc++.h>
using namespace std;

// 1. Adjacency matrix 
// O(N^2)

void Adjacency_matrix(){
    int n,m;  // nxm
    cin >> n >> m;
    
    // declare the adjacency matrix
    int adj[n+1][n+1];
    
    // take edges as input
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// 1. Adjacency List
// O(N+2E)

void Adjacency_List(){
    int n,m;
    cin >> n >> m;
    
    // Case - 1 and 2 => Undirected or Directed Graph
    vector<int> adj1[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        
        // If Undirected Gaph
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        
        // If Directed Gaph
        adj1[u].push_back(v);
    }
    
     // Case - 3 => Weighted Graph
    vector<pair<int,int>> adj2[n+1];
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        
        // If Undirected Gaph
        adj2[u].push_back({v,wt});
        adj2[v].push_back({u,wt});
    
}

int main()
{
    Adjacency_matrix();
    Adjacency_List();
    
    return 0;
}