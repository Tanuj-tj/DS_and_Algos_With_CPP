class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    
	    // Storing visited elements 
	    vector<int> bfs;
	    
	    // Visited array , initially vis = {0 0 0..V} 
	    vector<int> vis(V, 0);
	    
	    queue<int> q;
	    
	    q.push(0);
	    
	    vis[0] = 1;
	    
	    while(!q.empty()){
	                
	       int node = q.front();
	       q.pop();
	                
	       // Push the first element in the queue to the bfs array
	       bfs.push_back(node);
	                
	       for(auto it: adj[node]){
	           if(!vis[it]){
	               q.push(it);
	               vis[it] = 1;
	           }
	       }
	    }
	        
	    
	    
	    return bfs;
	    
	}
};
