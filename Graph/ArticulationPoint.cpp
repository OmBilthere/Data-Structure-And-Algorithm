class Solution {
  public:
  
    void dfs(int node , int parent , int & timer , vector<vector<int>>& adj , vector<int>& low ,
   
    vector<int>& tin , vector<int>& vis , vector<int> & mark ) {
        
        vis[node] = 1;
        
        tin[node] = low[node] = timer++;
        
        int child = 0;  
        
        for(auto it : adj[node]) {  
            
            if(it == parent) continue;
            
            if(!vis[it]) {
              
                
                dfs(it , node , timer , adj , low , tin , vis , mark);
                
                low[node] = min ( low[node] , low[it]);
                
                if( parent != -1 && tin[node] <= low[it]) {
                    
                      mark[node] = 1;
                     
                }
                
                child++;
        
            }
            
            else 
            
            low[node] = min (low[node] , tin[it]);
            
        }
        
        
        if(parent == -1 && child > 1) 
        
        mark[node] = 1;
    }
    
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(V);
        
        for(auto & it: edges) {
            
            adj[it[0]].push_back(it[1]);
            
            adj[it[1]].push_back(it[0]);
            
        }
        
        
        vector<int> tin(V), low(V) , vis(V , 0) , mark(V , 0) , articulations;
        
        int timer = 0;
        
        for(int node = 0 ; node < V ; node++ ) {
            
            if(!vis[node])
            
            dfs(node , -1 , timer , adj , low , tin, vis , mark);
        }
        
        for(int i=0 ; i<V ; i++) {
        
        if(mark[i])
        
        articulations.push_back(i);
        
        }
        
         if (articulations.size() == 0 ) 
         
         return {-1};
         
         return articulations;
    }
};